
# 1. Create a simulator object
set ns [new Simulator]

# 2. Open trace and nam files
set tracefile [open out.tr w]
$ns trace-all $tracefile

set namfile [open out.nam w]
$ns namtrace-all $namfile

# 3. Define a finish procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam out.nam &
    exit 0
}

# 4. Enable Distance Vector Routing
$ns rtproto DV

# 5. Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# 6. Create duplex links
$ns duplex-link $n0 $n1 1Mb 200ms DropTail
$ns duplex-link $n1 $n2 1Mb 200ms DropTail
$ns duplex-link $n2 $n3 1Mb 200ms DropTail

# 7. Create UDP agent
set udp [new Agent/UDP]
$ns attach-agent $n0 $udp

# 8. Create CBR application
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 500
$cbr set interval_ 0.05
$cbr attach-agent $udp

# 9. Create Null agent
set nul [new Agent/Null]
$ns attach-agent $n3 $nul

# 10. Connect UDP and Null agents
$ns connect $udp $nul

# 11. Schedule link failure and recovery
$ns rtmodel-at 1.0 down $n1 $n2
$ns rtmodel-at 2.0 up $n1 $n2

# 12. Start and stop CBR traffic
$ns at 0.1 "$cbr start"
$ns at 4.5 "$cbr stop"

# 13. Schedule simulation end
$ns at 5.0 "finish"

# 14. Run simulation
$ns run
