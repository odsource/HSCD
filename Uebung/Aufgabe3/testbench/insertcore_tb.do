onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -format Logic /insertcore_tb/rst
add wave -noupdate -format Logic /insertcore_tb/hlt
add wave -noupdate -format Logic /insertcore_tb/clk
add wave -noupdate -format Logic /insertcore_tb/swrst
add wave -noupdate -format Literal /insertcore_tb/cnt
add wave -noupdate -format Logic /insertcore_tb/strt
add wave -noupdate -format Logic /insertcore_tb/done
add wave -noupdate -format Literal -radix unsigned /insertcore_tb/len
add wave -noupdate -format Literal -radix unsigned /insertcore_tb/ptr
add wave -noupdate -format Logic /insertcore_tb/enb
add wave -noupdate -format Logic /insertcore_tb/web
add wave -noupdate -format Literal -radix ascii /insertcore_tb/dob
add wave -noupdate -format Literal -radix ascii /insertcore_tb/dib
add wave -noupdate -format Literal -radix unsigned /insertcore_tb/adr
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {3550000 ps} 0}
configure wave -namecolwidth 162
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 100
configure wave -griddelta 40
configure wave -timeline 0
update
WaveRestoreZoom {0 ps} {16443 ns}
