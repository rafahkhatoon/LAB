
# Create a simulator object
set ns [new Simulator]

# Set color
$ns color 1 Blue

# Open NAM trace file
set nf [open out.nam w]
$ns namtrace-all $nf

# Define finish procedure
proc finish {} {
    global ns nf
    $ns flush-trace
    close $nf
    exec nam out.nam &
    exit 0
}

# Create two nodes
set n0 [$ns node]
set n1 [$ns node]

# Create labels for nodes
$ns at 0.0 "$n0 label \"Sender\""
$ns at 0.0 "$n1 label \"Receiver\""

# Setup duplex link
$ns duplex-link $n0 $n1 1Mb 200ms DropTail

# Set link orientation
$ns duplex-link-op $n0 $n1 orient right

# Create a TCP agent
set tcp [new Agent/TCP]

# Attach TCP agent to first node
$ns attach-agent $n0 $tcp

$tcp set fid_ 1
$tcp set window_ 1
$tcp set maxcwnd_ 1

# Create TCP sink agent
set tcpsink [new Agent/TCPSink]

# Attach sink to second node
$ns attach-agent $n1 $tcpsink

# Connect TCP and TCP sink
$ns connect $tcp $tcpsink

# Create FTP application
set ftp [new Application/FTP]

# Attach FTP to TCP agent
$ftp attach-agent $tcp

# Start and stop FTP
$ns at 0.5 "$ftp start"
$ns at 3.0 "$ftp stop"

# Trace annotations
$ns at 1.0 "$ns trace-annotate \"Send Packet 1\""
$ns at 1.4 "$ns trace-annotate \"Receive Packet 1\""

$ns at 2.0 "$ns trace-annotate \"Send Packet 2\""
$ns at 2.5 "$ns trace-annotate \"Receive Packet 2\""

$ns at 3.2 "$ns trace-annotate \"Send Packet 3\""
$ns at 3.5 "$ns trace-annotate \"Receive Packet 3\""
$ns at 3.8 "$ns trace-annotate \"Receiver Packet 3\""

# Schedule simulation end
$ns at 4.0 "finish"

# Run simulation
$ns run
