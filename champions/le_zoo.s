.name		"Le singe de guerre"
.comment	"L'union des animaux, tout commença par une marmotte et un singe ..."

init:
rest:
fork %:go
live %0
fork %:go2
live %0
fork %:go3
prelive:
ld %251658255, r2
ld %1, r12
ld %40, r11
st r1, 11
st r16, -4
shield:
live %0
st r16, -300
st r2, -301
st r2, -302
sub r11, r12, r11
zjmp %:forking
ld %0, r16
zjmp %:shield
fork %:live

live:
live %0

go:
ld %0, r16
zjmp %:assaut1

go2:
ld %0, r16
zjmp %:assaut2

go3:
ld %0, r16
zjmp %:assaut3

forking:
ldi %:shield, %1, r13
ld %0, r16
st r13, 6
fork	%:shield
fork	%:attack
forkcycle:
live %0
fork	%:forking
fork %:forkcycle

start1:
zjmp %3
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
start2:
sti r10, r11, r12
sti r7, r8, r12
live %0

assaut2:
live %0
ld %190055920, r10 # sti r6, r7
ld %84476411, r11 # r5 jump 01F5 (501)
ld %150994970, r3 #0x0900000c
ld %150994995, r6 #0x0900000c
ld %26, r7
ld %495, r4
ld %0, r5
zjmp %:jump

attack:
st r10, 1
st r11, 2
st r12, 3
st r13, 4
fork %:attack
zjmp %:jump


assaut1:
live %0
ld %190055943, r10 # sti r6, r7
ld %84476405, r11 # r5 jump 01F5 (501)
fork %:second_assault
ld %190055172, r3 #0x0B540304
ld %190055172, r6 #0x0B540304
ld %507, r7
ld %24, r4
ld %0, r5
live %0
zjmp %:jump

assaut3:
live %0
ld %190055949, r10 # sti r6, r7
ld %84476409, r5
fork %:second_assault
live %0
zjmp %:jump

second_assault:
live %0
ld %84475923, r3 #0x0509001b
ld %84475923, r6
ld %511, r7
ld %28, r4
ld %0, r5
zjmp %:jump

jump:
live %0
st r10, 511
st r11, 510
zjmp %501