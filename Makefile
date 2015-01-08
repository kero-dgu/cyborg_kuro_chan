# 参考：http://gmaj7sus4.hatenablog.com/entry/2013/12/18/165224

TARGET		= CyborgKuroChan
INCLUDES	= -I./include
ifeq ($(OS),Windows_NT)
	LDLIBS  = -lfreeglut  -lglu32 -lopengl32 -liconv
else
	# gcc では math library にリンクできていないため, -lm オプションで手動リンクが必要
	LDLIBS  = -lglut -lGLU -lGL -liconv -lm
endif
NOMAKEDIR	= .git% data% doc% src/bin%
OBJDIR		= objs

GCC			= gcc
# -MMD を使うことで #include しているヘッダファイルの依存関係を解決してくれる
# -DDEBUG は完成前に消す
CFLAGS	= -O2 -MMD -MP -Wall -DDEBUG
CS			= $(shell find * -name "*.c")
SRCS		= $(filter-out $(NOMAKEDIR), $(CS))
DIRS		= $(dir $(SRCS))
BINDIRS	= $(addprefix $(OBJDIR)/, $(DIRS))

# patsubst は空白で区切られたものか指定の文字列に置換
OBJS	= $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(SRCS)))
DEPS	= $(OBJS:.o=.d)
TILS	= $(patsubst %.c, %.c~, $(SRCS))

ifeq "$(strip $(OBJDIR))" ""
	OBJDIR = .
endif

ifeq "$(strip $(DIRS))" ""
	OBJDIR = .
endif

.PYTHON: default
default:
	@[ -d  $(OBJDIR)   ] || mkdir -p $(OBJDIR)
	@[ -d "$(BINDIRS)" ] || mkdir -p $(BINDIRS)
	@make all --no-print-directory

.PYTHON: all
all : $(OBJS) $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(GCC) -o $@ $^ $(LDLIBS)

$(OBJDIR)/%.o: %.c
	$(GCC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PYTHON: clean
clean:
	@rm -rf $(TARGET) $(TILS) $(OBJDIR)

-include $(DEPS)
