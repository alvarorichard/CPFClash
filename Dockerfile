FROM rust:alpine3.17
WORKDIR /rs
COPY ./rs .
RUN cargo build --release

FROM golang:1.19-alpine3.17
WORKDIR /go
COPY ./golang .
RUN go build main.go

FROM alpine:3.17
WORKDIR /cpp
RUN apk add --no-cache g++ libstdc++ libgcc
COPY ./cpp .
RUN g++ -o main main.cpp cpf.hpp cpf.cpp


FROM alpine:3.17
WORKDIR /app
COPY --from=0 /rs/target/release/rs /app/rs
COPY --from=1 /go/main /app/go
COPY --from=2 /cpp/main /app/cpp
