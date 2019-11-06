# Get the base Ubuntu image from Docker Hub
FROM ubuntu:18.04
 
# Update apps on the base image
RUN apt-get -y update && apt-get install -y && apt-get -y upgrade
 
# Install the Clang compiler
RUN apt-get -y install clang
RUN apt-get -y install make

# Install useful libs
RUN apt-get -y install dos2unix
RUN apt-get install -y openjdk-8-jdk
ENV JAVA_HOME /usr/lib/jvm/java-8-openjdk-amd64/

# Install required cmake version
ADD https://cmake.org/files/v3.14/cmake-3.14.1-Linux-x86_64.sh /cmake-3.14.1-Linux-x86_64.sh
RUN mkdir /opt/cmake
RUN sh /cmake-3.14.1-Linux-x86_64.sh --prefix=/opt/cmake --skip-license
RUN ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake
RUN cmake --version

ADD install.sh /usr/local/bin/install.sh
RUN dos2unix /usr/local/bin/install.sh
RUN chmod 777 /usr/local/bin/install.sh
ADD build_config.sh /usr/local/bin/build_config.sh
RUN chmod 777 /usr/local/bin/build_config.sh
RUN dos2unix /usr/local/bin/build_config.sh
RUN ln -s /usr/local/bin/build_config.sh / # backwards compat

ENTRYPOINT ["build_config.sh"]