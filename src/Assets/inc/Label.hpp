// Copyright © 2022 David Bogdan

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files 
// (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, 
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do 
// so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


/**
 * @file Label.hpp
 * @author David Bogdan
 * @brief Definition of the Label class
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <Component.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include <FontManager.hpp>
#include <Exceptions/LabelException.hpp>
#include <Point.hpp>

namespace easyGUI
{

/**
 * @brief Implements a label component
 * 
 * @details This class is a wrapper around the sf::Text class, in order
 * to make the implementation of Labels easier for the end-user. For custom 
 * labels, you can inherit this class.
 */
class Label : public Component
{
private:
    ::std::shared_ptr<::sf::Font> _font;
    ::sf::Text _text;
    ::sf::Color _textColor;

    virtual void draw(::sf::RenderTarget&, ::sf::RenderStates) const;

    // ----- Initializers -----

    /**
     * @brief Initializes the label's text
     * 
     * @param location The position of the text
     * @param text The text of the label
     * @param charSize The character size
     */
    void constructText(const Point&, const ::std::string&, const unsigned&);

public:
    /**
     * @brief Destructor
     * 
     */
    ~Label();

    /**
     * @brief Constructor
     * 
     * @param position The position where the text should be placed.
     * @param text The text to be displayed.
     * @param fontPath The path to the font file.
     * @param charSize The size of the characters.
     * 
     * @throw LabelException Invalid font path or couldn't get FontManager
     * 
     * @note The font file format must be .ttf
     */
    explicit Label(const Point&, const ::std::string&, const ::std::string&, const unsigned&);

    // Block other forms of construction

    Label()= delete;
    Label(const Label&)= delete;
    Label& operator= (const Label&)= delete;

    // ----- Auxiliaries -----

    /**
     * @brief Check if mouse is over the button
     * 
     * @return true Mouse is over the label
     * @return false otherwise
     */
    bool isMouseHover() const;

    // ----- Getters -----

    /**
     * @brief Returns the SFML text object
     * 
     * @return ::sf::Text& 
     */
    ::sf::Text& getInternalText();

    /**
     * @brief Updates a component's location
     * 
     * @param newLocation The new location of the component
     */
    virtual void updateLocation(const Point&);
};

}