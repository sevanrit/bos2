.PHONY: all clean deb install

all:
	$(MAKE) -C libbos2
	$(MAKE) -C libbos2-text
	$(MAKE) -C libbos2-json
	$(MAKE) -C bos2-client
	$(MAKE) -C bos2-daemon

clean:
	$(MAKE) -C libbos2 clean
	$(MAKE) -C libbos2-text clean
	$(MAKE) -C libbos2-json clean
	$(MAKE) -C bos2-client clean
	$(MAKE) -C bos2-daemon clean

deb:
	dpkg-buildpackage -us -uc

install:
	$(MAKE) -C libbos2 install
	$(MAKE) -C libbos2-text install
	$(MAKE) -C libbos2-json install
	$(MAKE) -C bos2-client install
	$(MAKE) -C bos2-daemon install
