# Сборка ---------------------------------------

# В качестве базового образа для сборки используем gcc:latest
FROM opencvcourses/opencv-docker:latest

# Установим рабочую директорию для сборки GoogleTest
WORKDIR /gtest_build

# Скачаем все необходимые пакеты и выполним сборку GoogleTest
# Такая длинная команда обусловлена тем, что
# Docker на каждый RUN порождает отдельный слой,
# Влекущий за собой, в данном случае, ненужный оверхед
RUN apt-get update && \
    apt-get install -y \
    	wget\
	unzip\
        doxygen \
	cmake
RUN wget https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip 
RUN ls
RUN unzip 609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
RUN cmake -DCMAKE_BUILD_TYPE=Release googletest-609281088cfefc76f9d0ce82e1ff6c30cc3591e5 && \
    cmake --build . && \
    make -j && \
    make install

RUN ls 
RUN ls lib/
 
 #RUN    mv lib/*.a /usr/lib
RUN ls

# Скопируем директорию /src в контейнер
ADD ./fff /app/fff
RUN ls /usr/lib
# Установим рабочую директорию для сборки проекта
WORKDIR /app/build

# Выполним сборку нашего проекта, а также его тестирование
RUN  cmake ../fff && \
    cmake --build . && \
    CTEST_OUTPUT_ON_FAILURE=TRUE cmake --build . 
# Запуск ---------------------------------------

# В качестве базового образа используем ubuntu:latest
#FROM ubuntu:latest

# Установим рабочую директорию нашего приложения
#WORKDIR /app

# Скопируем приложение со сборочного контейнера в рабочую директорию
#COPY --from=build /app/build/FaceApp/Tests .

# Установим точку входа
