all: clean  Tree
Tree:
	@echo ""
	@echo "============================="
	@echo "|         Arvore            |"
	@echo "============================="
	@echo "Compilando Arvore."
	gcc ArvoreAvl.c ArvoreAvl.h main.c -o binarytree
	chmod +x binarytree

	
clean:
	@echo ""
	@echo "============================="
	@echo "|   REMOVENDO PROGRAMAS     |"
	@echo "============================="
	@echo "Removendo todos os arquivos compilados"
	rm -f binarytree