FROM ubuntu:20.04



RUN apt -y update && \
    apt -y upgrade && \ 
    apt install -yy gcc g++ gdb cmake && \
    apt install -yy ffmpeg libsm6 libxext6 && \
    apt -y install python3-pip && \
    apt install nano && pip3 install --upgrade pip && \
    rm -rf /var/lib/apt/lists/*

RUN apt install -y python3
RUN apt install -y python3-pip

WORKDIR /opt/app

COPY . .

# ENV TZ=Europe/Moscow

# RUN cp /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

ENTRYPOINT [ "python3" ]

CMD [ "-m", "http.server", "21222" ]

# docker build -t app .


