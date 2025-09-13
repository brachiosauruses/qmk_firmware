USER := khang

KEEB := keebio/iris
KEEB := dz60
KEEB := 1upkeyboards/pi60_hse

KEEB_REV := keebio/iris/rev4
KEEB_REV := $(KEEB)

CONTEXT := -kb $(KEEB_REV) -km $(USER)

MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR  := $(dir $(MAKEFILE_PATH))

INSERT_DIR := $(MAKEFILE_DIR)../keyboards/$(KEEB)/keymaps/$(USER)

build:
	@rm -rf $(INSERT_DIR)
	ln -sf $(MAKEFILE_DIR)$(KEEB) $(INSERT_DIR)
	qmk compile --compiledb -j 4 $(CONTEXT)

f:
	qmk flash $(CONTEXT)
