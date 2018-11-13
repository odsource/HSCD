onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -format Logic /system_tb/clk
add wave -noupdate -format Logic /system_tb/hlt
add wave -noupdate -format Logic /system_tb/led1
add wave -noupdate -format Logic /system_tb/txd
add wave -noupdate -format Logic /system_tb/rxd
add wave -noupdate -format Logic /system_tb/strb
add wave -noupdate -format Logic /system_tb/sys/interrupt
add wave -noupdate -format Literal -radix hexadecimal /system_tb/sys/address
add wave -noupdate -format Literal -radix hexadecimal /system_tb/sys/instruction
add wave -noupdate -format Literal /system_tb/src
add wave -noupdate -format Literal -radix decimal /system_tb/data
add wave -noupdate -format Literal -radix hexadecimal /system_tb/sys/out_port
add wave -noupdate -format Logic /system_tb/evn1
add wave -noupdate -format Logic /system_tb/evn2
add wave -noupdate -format Analog-Step -height 40 -scale 80.0 /system_tb/mes
add wave -noupdate -format Analog-Step -height 40 -scale 100.0 /system_tb/avg
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {7272530000 ps} 0}
configure wave -namecolwidth 226
configure wave -valuecolwidth 72
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
update
WaveRestoreZoom {0 ps} {10500 us}
