figura.pdf : datos.txt
	python purple_rain.py
	rm datos.txt
	rm temp.rs

datos.txt :
	c++ prince.cpp -o temp.rs
	./temp.rs > datos.txt
