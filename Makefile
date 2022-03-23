D := # New directory name

ifneq ($(D),)
new:
	mkdir -p $(D)
	cd $(D) && vim
endif

clean:
	rm .gitignore
	git clean -if
	git checkout .gitignore
