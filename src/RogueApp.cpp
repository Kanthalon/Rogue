/**
 * Provides the RogueApp class which implements the Rogue example game
 * for the GQE library.
 *
 * @file src/RogueApp.cpp
 * @author Ryan Lindeman
 * @date 20110704 - Initial Release
 */
#include "RogueApp.hpp"
#include "GameState.hpp"
 
RogueApp::RogueApp(const std::string theTitle) :
    GQE::IApp(theTitle)
{
}

RogueApp::~RogueApp()
{
}

void RogueApp::InitAssetHandlers(void)
{
  // No custom asset handlers needed or provided
}

void RogueApp::InitScreenFactory(void)
{
  // Add Game State as the next active state
  mStateManager.AddActiveState(new(std::nothrow) GameState(*this));
}

void RogueApp::HandleCleanup(void)
{
  // No custom cleanup needed
}