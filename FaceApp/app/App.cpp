#include "../include/FaceApp.h"

using namespace cv;
using namespace std;

/********************************************//**
 *  ... The most important function of our project.
 * Reads cascade files and masks, then reads the stream from the camera,
 * looks for a face in the picture and puts a previously downloaded mask 
 * on this place.
 ***********************************************/
int main() {
    string faceCascadeName = "resources//face.xml";
    CascadeClassifier faceCascade;

    if (!faceCascade.load(faceCascadeName)) {
        cerr << "Error loading cascade file. Exiting!" << endl;
        return -1;
    }

    Mat faceMask = imread("resources/mask.jpg");

    if (!faceMask.data) {
        cerr << "Error loading mask image. Exiting!" << endl;
    }

    
    Mat frame, frameGray; /**< Current frame */
    Mat frameROI, faceMaskSmall;
    Mat grayMaskSmall, grayMaskSmallThresh, grayMaskSmallThreshInv;
    Mat maskedFace, maskedFrame;

    VideoCapture cap(0); /**< Create the capture object
    0 -> input arg that specifies it should take the input from the webcam */
    

    if (!cap.isOpened()) { ///< If you cannot open the webcam, stop the execution!
        cerr << "Error with webcam";
        return -1;
    }
    
    namedWindow("FaceApp",WINDOW_FULLSCREEN); ///< create GUI windows

    
    float scalingFactor = 0.75; ///< Scaling factor to resize the input frames from the webcam

    vector<Rect> faces;

    
    while (true) ///< Iterate until the user presses the Esc key
    {
        
        cap >> frame; ///< Capture the current frame

       
        resize(frame, frame, Size(), scalingFactor, scalingFactor, INTER_AREA); ///< Resize the frame

        
        cvtColor(frame, frameGray, COLOR_BGR2GRAY); ///< Convert to grayscale

        
        equalizeHist(frameGray, frameGray); ///< Equalize the histogram

        
        faceCascade.detectMultiScale(frameGray, faces, 1.1, 2, 0 | 2, Size(30, 30)); ///< Detect faces

        
        for (auto& face : faces) ///< Draw green rectangle around the face
        {
            Rect faceRect(face.x, face.y, face.width, face.height);

            
            int x = face.x - int(0.1 * face.width); ///< Custom parameters to make the mask fit your face. You may have to play around with them to make sure it works.
            int y = face.y - int(0.0 * face.height);///< Custom parameters to make the mask fit your face. You may have to play around with them to make sure it works.
            int w = int(1.1 * face.width); ///< Custom parameters to make the mask fit your face. You may have to play around with them to make sure it works.
            int h = int(1.3 * face.height); ///< Custom parameters to make the mask fit your face. You may have to play around with them to make sure it works.

            
            frameROI = frame(Rect(x, y, w, h)); ///< Extract region of interest (ROI) covering your face

            resize(faceMask, faceMaskSmall, Size(w, h)); ///< Resize the face mask image based on the dimensions of the above ROI


            
            cvtColor(faceMaskSmall, grayMaskSmall, COLOR_BGR2GRAY);///< Convert the above image to grayscale

            
            threshold(grayMaskSmall, grayMaskSmallThresh, 230, 255, THRESH_BINARY_INV);///< Threshold the above image to isolate the pixels associated only with the face mask

            
            bitwise_not(grayMaskSmallThresh, grayMaskSmallThreshInv);///< Create mask by inverting the above image (because we don't want the background to affect the overlay)

            
            bitwise_and(faceMaskSmall, faceMaskSmall, maskedFace, grayMaskSmallThresh);///< Use bitwise "AND" operator to extract precise boundary of face mask

            
            bitwise_and(frameROI, frameROI, maskedFrame, grayMaskSmallThreshInv);///< Use bitwise "AND" operator to overlay face mask

            
            if (x > 0 && y > 0 && x + w < frame.cols && y + h < frame.rows)
                add(maskedFace, maskedFrame, frame(Rect(x, y, w, h)));///< Add the above masked images and place it in the original frame ROI to create the final image
        }

        imshow("FaceApp", frame);///< Show the current frame

        auto ch = waitKey(30);///< Get the keyboard input and check if it's 'Esc'
        if (ch == 27) {
            break;
        }
    }

    
    cap.release();///< Release the video capture object

    
    destroyAllWindows(); ///< Close all windows

    return 1;
}