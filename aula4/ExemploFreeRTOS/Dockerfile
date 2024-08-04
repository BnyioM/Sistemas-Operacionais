FROM ubuntu:20.04
RUN apt-get update
RUN apt-get install python3-pip -y
RUN pip3 install --upgrade pip
RUN pip3 install notebook
RUN apt-get install libc6-dev-i386 -y

EXPOSE 8889
