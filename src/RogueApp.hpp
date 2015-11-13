/**
 * Provides the RogueApp class which implements the Rogue example game
 * for the GQE library.
 *
 * @file src/RogueApp.hpp
 * @author Ryan Lindeman
 * @date 20110704 - Initial Release
 */
#ifndef   ROGUE_APP_HPP_INCLUDED
#define   ROGUE_APP_HPP_INCLUDED
 
#include <GQE/Core/interfaces/IApp.hpp>
 
/// Provides the core game loop algorithm for all game engines.
class RogueApp : public GQE::IApp
{
public:
  /**
   * RogueApp constructor
   * @param[in] theTitle is the title of the window
   */
  RogueApp(const std::string theTitle = "Rogue");

  /**
   * RogueApp deconstructor
   */
  virtual ~RogueApp();

protected:
  /**
    * InitAssetHandlers is responsible for registering custom IAssetHandler
    * derived classes for a specific game application.
    */
  virtual void InitAssetHandlers(void);

  /**
    * InitScreenFactory is responsible for initializing any IScreen derived
    * classes with the ScreenManager class that will be used to create new
    * IScreen derived classes as requested.
    */
  virtual void InitScreenFactory(void);

  /**
    * HandleCleanup is responsible for performing any custom last minute
    * Application cleanup steps before exiting the Application.
    */
  virtual void HandleCleanup(void);

private:
}; // class RogueApp

#endif // ROGUE_APP_HPP_INCLUDED
/**
 * @class RogueApp
 * @ingroup Examples
 * The RogueApp class is the App class for the Rogue example game
 * in the GQE library.
 *
 * Copyright (c) 2010-2011 Ryan Lindeman
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
