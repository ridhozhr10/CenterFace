## CenterFace - alpine test

dockerized version running on alpine, image size (40.8MB)

### run

```
$ docker build -t centerface-alpine .
$ mkdir test
$ cd test
$ cp <your_jpg_file>.jpg .
$ docker run --rm -it -v $(pwd):/data centerface-alpine <your_jpeg_file>.jpg
```

result image (with boundingbox) will be in `/<dir>/test/hasil.jpg`

### test host

- ubuntu 18.04
