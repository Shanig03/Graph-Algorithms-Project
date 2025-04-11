CC = gcc
CFLAGS = -Wall

all: sender receiver

sender: signalSender.c
	$(CC) $(CFLAGS) -o sender signalSender.c

receiver: signalReciever.c
	$(CC) $(CFLAGS) -o receiver signalReciever.c

clean:
	rm -f sender receiver gmon.out analysis.txt

run: sender receiver
	@echo "Start receiver in one terminal, using ./receiver"
	@echo "Then run sender in another terminal, using ./sender"
