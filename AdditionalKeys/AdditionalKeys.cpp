#include "AdditionalKeys.h"
#include <windows.h>

AdditionalKeys *pPlugin = nullptr;

bool AdditionalKeys::Initialize(IAshitaCore *core, ILogManager *logger, const uint32_t id)
{
    m_AshitaCore = core;
    m_LogManager = logger;
    m_PluginId = id;
    pPlugin = this;

    // Add the callback using the specified constructor
    m_AshitaCore->GetInputManager()->GetKeyboard()->AddCallback("AdditionalKeys_cb",
                                                                nullptr, // device data callback
                                                                nullptr, // device state callback
                                                                AdditionalKeys::KeyboardCallback);

    return true;
}

void AdditionalKeys::Release(void)
{
}

BOOL __stdcall AdditionalKeys::KeyboardCallback(WPARAM wParam, LPARAM lParam, bool handled)
{
    if (pPlugin == nullptr || pPlugin->m_AshitaCore == nullptr)
        return FALSE;

    WORD vkCode = LOWORD(wParam);
    WORD keyFlags = HIWORD(lParam);
    WORD scanCode = LOBYTE(keyFlags);
    BOOL isExtendedKey = (keyFlags & KF_EXTENDED) == KF_EXTENDED;
    if (isExtendedKey)
        scanCode = MAKEWORD(scanCode, 0xE0);
    BOOL wasKeyDown = (keyFlags & KF_REPEAT) == KF_REPEAT;
    WORD repeatCount = LOWORD(lParam);
    BOOL isKeyReleased = (keyFlags & KF_UP) == KF_UP;

    if (isKeyReleased)
        return FALSE;

    switch (vkCode)
    {
    case VK_F13:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f13");
        return true;
    case VK_F14:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f14");
        return true;
    case VK_F15:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f15");
        return true;
    case VK_F16:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f16");
        return true;
    case VK_F17:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f17");
        return true;
    case VK_F18:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f18");
        return true;
    case VK_F19:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f19");
        return true;
    case VK_F20:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f20");
        return true;
    case VK_F21:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f21");
        return true;
    case VK_F22:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f22");
        return true;
    case VK_F23:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f23");
        return true;
    case VK_F24:
        pPlugin->m_AshitaCore->GetChatManager()->QueueCommand(1, "/additionalkeys_f24");
        return true;
    }

    return false;
}
