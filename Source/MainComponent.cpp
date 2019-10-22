/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(textLabel);
    textLabel.setFont(textFont);
    
    addAndMakeVisible(styleMenu);
    styleMenu.addItem("Plain", stylePlain);
    styleMenu.addItem("Bold", styleBold);
    styleMenu.addItem("Italic", styleItalic);
    styleMenu.onChange = [this] { styleMenuChanged(); };
    styleMenu.setSelectedId(stylePlain);
    
    addAndMakeVisible(coloursMenu);
    coloursMenu.addItem("Black", black);
    coloursMenu.addItem("White", white);
    coloursMenu.addSeparator();
    coloursMenu.addSectionHeading("Reds");
    coloursMenu.addItem("Red", red);
    coloursMenu.addItem("Dark Red", darkred);
    coloursMenu.addItem("Indian Red", indianred);
    coloursMenu.addSeparator();
    coloursMenu.addSectionHeading("Greens");
    coloursMenu.addItem("Green", green);
    coloursMenu.addItem("Dark Green", darkgreen);
    coloursMenu.addItem("Light Green", lightgreen);
    coloursMenu.addSeparator();
    coloursMenu.addSectionHeading("Blues");
    coloursMenu.addItem("Blue", blue);
    coloursMenu.addItem("Dark Blue", darkblue);
    coloursMenu.addItem("Light Blue", lightblue);
    coloursMenu.onChange = [this] { coloursMenuChanged(); };
    coloursMenu.setSelectedId(black);
    coloursMenu.setEditableText(true);
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    textLabel.setBounds(10, 10, getWidth() - 20, 20);
    styleMenu.setBounds(10, 40, getWidth() - 20, 20);
    coloursMenu.setBounds(10, 70, getWidth() - 20, 20);
}

void MainComponent::styleMenuChanged()
{
    switch (styleMenu.getSelectedId()) {
        case stylePlain:
            setLightColoursEnabled(true);
            textFont.setStyleFlags(Font::plain);
            break;
        case styleBold:
            if ((coloursMenu.getSelectedId() == white) || (coloursMenu.getSelectedId() == indianred) || (coloursMenu.getSelectedId() == lightgreen) || (coloursMenu.getSelectedId() == lightblue))
            {
                coloursMenu.setSelectedId(coloursMenu.getSelectedId() - 1);
            }
            setLightColoursEnabled(false);
            textFont.setStyleFlags(Font::bold);
            break;
        case styleItalic:
            setLightColoursEnabled(true);
            textFont.setStyleFlags(Font::italic);
            break;
    }
    textLabel.setFont (textFont);
}

void MainComponent::coloursMenuChanged()
{
    Colour textColour;
    switch (coloursMenu.getSelectedId()) {
        case black: textColour = Colours::black; break;
        case white: textColour = Colours::white; break;
        case red: textColour = Colours::red; break;
        case darkred: textColour = Colours::darkred; break;
        case indianred: textColour = Colours::indianred; break;
        case green: textColour = Colours::green; break;
        case darkgreen: textColour = Colours::darkgreen; break;
        case lightgreen: textColour = Colours::lightgreen; break;
        case blue: textColour = Colours::blue; break;
        case darkblue: textColour = Colours::darkblue; break;
        case lightblue: textColour = Colours::lightblue; break;
        default:
            textColour = handleColourText();
            break;
    }
    textLabel.setColour (Label::textColourId, textColour);
}

Colour MainComponent::handleColourText()
{
    auto menuText = coloursMenu.getText();
    auto valueFromHex = menuText.getHexValue32();
//    coloursMenu.setText(String::toHexString((int) valueFromHex));
    
    int hexIsUnique = 0;
    for (int i = 0; i < coloursMenu.getNumItems(); ++i) {
        if (coloursMenu.getItemText(i) == coloursMenu.getText())
        {
            hexIsUnique = 1;
        }
    }
    if (hexIsUnique == 0)
    {
        if (coloursMenu.getNumItems() == 11) {
            coloursMenu.addSeparator();
            coloursMenu.addSectionHeading("Custom");
        }
        coloursMenu.addItem(String::toHexString((int) valueFromHex), coloursMenu.getNumItems() + 1);
    }
    
    return Colour (valueFromHex);
}

void MainComponent::setLightColoursEnabled (const bool shouldBeEnabled)
{
    coloursMenu.setItemEnabled(white, shouldBeEnabled);
    coloursMenu.setItemEnabled(indianred, shouldBeEnabled);
    coloursMenu.setItemEnabled(lightgreen, shouldBeEnabled);
    coloursMenu.setItemEnabled(lightblue, shouldBeEnabled);
}
