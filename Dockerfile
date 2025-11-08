# Light-Weight Docker image for C++
FROM alpine:3.18

WORKDIR /workspace

# Install packages removing cache
RUN apk update && \
    apk add --no-cache build-base && \
    rm -rf /var/cache/apk/*

CMD ["/bin/sh"]

