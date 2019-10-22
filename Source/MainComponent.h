/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    enum FontStyles
    {
        stylePlain = 1,
        styleBold,
        styleItalic,
        numberOfStyles
    };
    
    enum TextColours
    {
        black = 1,
        white,
        red,
        darkred,
        indianred,
        green,
        darkgreen,
        lightgreen,
        blue,
        darkblue,
        lightblue,
        numberOfColours
    };
    
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void styleMenuChanged();
    void coloursMenuChanged();
    Colour handleColourText();
    void setLightColoursEnabled (const bool);

private:
    Label textLabel { {}, "The quick brown fox jumps over the lazy dog." };
    Font textFont { 12.0f };
    ComboBox styleMenu, coloursMenu;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
