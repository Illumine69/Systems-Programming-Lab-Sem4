libraries :
	cd trie; make library; sudo make install
	cd util; make library; sudo make install

maxchain :
	@export LD_LIBRARY_PATH=/usr/local/lib; cd apps; make maxchain

subwords :
	@export LD_LIBRARY_PATH=/usr/local/lib; cd apps; make subwords

clean :
	cd trie; make clean
	cd util; make clean
	cd apps; make clean