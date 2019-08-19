FROM ubuntu:bionic

RUN apt-get update
RUN apt-get install -y software-properties-common
RUN sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main' -y
RUN apt-get -y install curl gcc g++ python3 python3-venv make perl unzip git