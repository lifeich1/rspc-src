D := # New directory name

ifneq ($(D),)
new:
	mkdir -p $(D)
	cd $(D) && vim
endif

.PHONY: lc
lc:
	nc -l 13013

clean:
	rm .gitignore
	git clean -if
	git checkout .gitignore
