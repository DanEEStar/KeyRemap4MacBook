#ifndef VIRTUALKEY_HPP
#define VIRTUALKEY_HPP

#include "bridge.hpp"
#include "CallbackWrapper.hpp"
#include "KeyCode.hpp"
#include "TimerWrapper.hpp"

namespace org_pqrs_KeyRemap4MacBook {
  class VirtualKey {
  public:
    static void initialize(IOWorkLoop& workloop);
    static void terminate(void);
  };

  // ----------------------------------------------------------------------
  class Handle_VK_LOCK {
  public:
    static bool handle(const Params_KeyboardEventCallBack& params);
  };

  // ----------------------------------------------------------------------
  class Handle_VK_STICKY {
  public:
    static bool handle(const Params_KeyboardEventCallBack& params);
  };

  // ----------------------------------------------------------------------
  class Handle_VK_LAZY {
  public:
    static bool handle(const Params_KeyboardEventCallBack& params);
  };

  // ----------------------------------------------------------------------
  class Handle_VK_CHANGE_INPUTMODE {
  public:
    static bool handle(const Params_KeyboardEventCallBack& params);
  };

  // ----------------------------------------------------------------------
  class Handle_VK_CONFIG {
  public:
    static bool handle(const Params_KeyboardEventCallBack& params);
  };

  // ----------------------------------------------------------------------
  class Handle_VK_JIS_TOGGLE_EISUU_KANA {
  public:
    static bool handle(Params_KeyboardEventCallBack& params);

  private:
    // It is necessary to save toKeyCode for KeyUp.
    static KeyCode newkeycode_;
  };

  bool handle_VK_JIS_EISUU_x2(const Params_KeyboardEventCallBack& params);
  bool handle_VK_JIS_KANA_x2(const Params_KeyboardEventCallBack& params);
  bool handle_VK_JIS_BACKSLASH(Params_KeyboardEventCallBack& params);
  bool handle_VK_JIS_YEN(Params_KeyboardEventCallBack& params);

  // ----------------------------------------------------------------------
  class Handle_VK_JIS_TEMPORARY {
  public:
    static void initialize(IOWorkLoop& workloop);
    static void terminate(void);

    static bool handle(Params_KeyboardEventCallBack& params);

  private:
    enum {
      KEYEVENT_DELAY_MS = 100,
    };
    static bool handle_core(const Params_KeyboardEventCallBack& params,
                            KeyCode key,
                            const KeyRemap4MacBook_bridge::GetWorkspaceData::InputModeDetail& inputmodedetail);
    static bool handle_RESTORE(const Params_KeyboardEventCallBack& params);

    static void firekeytoinputdetail(const Params_KeyboardEventCallBack& params,
                                     KeyRemap4MacBook_bridge::GetWorkspaceData::InputModeDetail inputmodedetail);

    static KeyRemap4MacBook_bridge::GetWorkspaceData::InputModeDetail normalize(const KeyRemap4MacBook_bridge::GetWorkspaceData::InputModeDetail& imd);

    static void fire(OSObject* notuse_owner, IOTimerEventSource* notuse_sender);
    static void fire_nolock(void);

    static KeyRemap4MacBook_bridge::GetWorkspaceData::InputModeDetail savedinputmodedetail_;
    static KeyRemap4MacBook_bridge::GetWorkspaceData::InputModeDetail currentinputmodedetail_;

    struct FireKeyInfo {
      Flags flags;
      KeyCode key;
      KeyboardType keyboardType;
      bool active;
    };
    static FireKeyInfo fireKeyInfo_;
    static TimerWrapper timer_;
  };
}

#endif
