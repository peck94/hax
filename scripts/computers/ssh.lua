require "scripts/computers/shell"

function checkAccess()
    io.write("Username: ")
    io.flush()
    local name = io.read()
    io.write("Password: ")
    io.flush()
    local password = io.read()

    if not GetUser(name) then
        return false
    end

    return User.getUserName() == name and User.getPassword() == password
end
