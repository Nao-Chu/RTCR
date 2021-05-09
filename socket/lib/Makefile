mver= 1
sver= 0.0
src = $(shell find . -name "*.cpp")
inc = $(shell find ../inc -name "*.h")
obj = $(src:%.cpp=%.o)
str = libmysocket.so.$(mver)
target = $(str).$(sver)

GCC = g++ -shared -Wl,-soname,$(str)


ALL = $(target)
$(target) : $(obj)
	$(GCC) -o $(target) $(obj)

%.o : %.cpp $(inc)
	g++ -fPIC -g -Wall -c $<

.PHONY : clean
clean:
	-rm -rf $(ALL) $(obj)
	    
