USER := khang

KEEB := keebio/iris/rev4
KEEB := dz60
KEEB := 1upkeyboards/pi60_hse

CONTEXT := -kb $(KEEB) -km $(USER)

MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR  := $(dir $(MAKEFILE_PATH))

build:
	ln -sf $(MAKEFILE_DIR)pi60 ../keyboards/$(KEEB)/keymaps/$(USER)
	qmk compile --compiledb -j 4 $(CONTEXT)

flash:
	qmk flash $(CONTEXT)
