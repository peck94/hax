io.write("host: ")
io.flush()
local host = io.read()
io.write("command: ")
io.flush()
local cmd = io.read()
if RPC(host, cmd) then
    print("The command completed successfully.")
else
    print("Cannot connect to remote host.")
end
