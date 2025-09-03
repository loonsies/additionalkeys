#ifndef __ADDITIONALKEYS_H_INCLUDED__
#define __ADDITIONALKEYS_H_INCLUDED__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "C:\Ashita\plugins\sdk\Ashita.h"

class AdditionalKeys : public IPlugin
{
private:
    IAshitaCore *m_AshitaCore;
    ILogManager *m_LogManager;
    uint32_t m_PluginId;

public:
    const char *GetName(void) const override { return "AdditionalKeys"; }
    const char *GetAuthor(void) const override { return "looney"; }
    const char *GetDescription(void) const override { return "Bind additional function keys (F13-F24) in Ashita v4"; }
    const char *GetLink(void) const override { return "https://github.com/loonsies/additionalkeys"; }
    double GetVersion(void) const override { return 1.00f; }
    int32_t GetPriority(void) const override { return 0; }
    uint32_t GetFlags(void) const override { return (uint32_t)Ashita::PluginFlags::UseCommands; }

    bool Initialize(IAshitaCore *core, ILogManager *logger, const uint32_t id) override;
    void Release(void) override;

    static BOOL __stdcall KeyboardCallback(WPARAM wParam, LPARAM lParam, bool handled);

    IAshitaCore *GetCore() const { return m_AshitaCore; }
};

#endif
