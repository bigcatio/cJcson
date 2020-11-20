NAME_APP = cJsonSample

TARGETS = $(NAME_APP)  
SRC = .

SOURCE_APP= $(wildcard ./*.c)  

OBJ_APP = $(patsubst %.c, %.o, $(SOURCE_APP))  

INCLUDE_COMMON = ./include/  

CFLAGS = -Wall -c  
CC = gcc  

all: $(TARGETS)  
$(NAME_APP): $(OBJ_APP)  
	@mkdir -p output/  
	$(CC) $(OBJ_APP) -o output/$(NAME_APP)  

%.o: %.c  
	$(CC) -I$(INCLUDE_COMMON) $(CFLAGS) $< -o $@  

.PHONY: clean  
clean:  
	rm -rf $(OBJ_APP) output/