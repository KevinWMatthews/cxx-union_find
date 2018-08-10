FROM gcc:7

# Inefficient for new users, but I already have both of these images built.
RUN apt-get update \
    && apt-get install -y \
    cmake=3.7.2-1 \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update \
    && apt-get install -y \
    libboost-all-dev=1.62.0.1 \
    && rm -rf /var/lib/apt/lists/*

# Build user into image. This image is not for distribution!
ARG user
RUN ["/bin/bash", "-c", ": ${user:?Build argument must be set}"]
RUN useradd --create-home $user
