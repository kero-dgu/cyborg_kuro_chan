# OpenGL - freeglut をコンパイル

CC		= gcc
# -MMD を使うことで #include しているヘッダファイルの依存関係を解決してくれる
CFLAGS	= -O2 -MMD -Wall
LDLIBS	= -lfreeglut  -lglu32 -lopengl32
SUBDIR	= controllers managers views
OBJDIR	= obj
SRCS	:=
REL		:= controllers/
include $(REL)Makefile
REL		:= managers/
include $(REL)Makefile
SRCS += main.c

TARGET	= CyborgKuroChan
OBJS	= $(SRCS:.c=.o)
DEPS	= $(SRCS:.c=.d)
TILDE	= $(SRCS:.c=.c~)


# サフィックス .c のファイルに対しては下記の生成コマンドを使って, サフィックス .o ファイルを生成する
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

.PYTHON: default
default:
	$(OBJS) $(TARGET)

.PYTHON: clean
clean:
	$(RM) $(OBJS) $(DEPS) $(TILDE) $(TARGET)

-include $(DEPS)
