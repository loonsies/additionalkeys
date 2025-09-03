addon.name = 'additionalkeys'
addon.version = '0.01'
addon.author = 'looney'

require 'common'
local chat = require('chat')

ashita.events.register('command', 'command_cb', function(cmd, nType)
    if not cmd or not cmd.command then
        return false
    end

    local args = cmd.command:args()
    if #args == 0 then
        return false
    end

    local command = string.lower(args[1])

    if command == '/additionalkeys_f13' then
    elseif command == '/additionalkeys_f14' then
    elseif command == '/additionalkeys_f15' then
    elseif command == '/additionalkeys_f16' then
    elseif command == '/additionalkeys_f17' then
    elseif command == '/additionalkeys_f18' then
    elseif command == '/additionalkeys_f19' then
    elseif command == '/additionalkeys_f20' then
    elseif command == '/additionalkeys_f21' then
    elseif command == '/additionalkeys_f22' then
    elseif command == '/additionalkeys_f23' then
    elseif command == '/additionalkeys_f24' then
    else
        return false
    end

    return true
end)
