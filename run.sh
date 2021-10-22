#!/usr/bin/env bash

VERSION=$(date +%s)

docker build . -t istream_block_iterator:${VERSION} && \
	docker run --rm -i -t istream_block_iterator:${VERSION}
