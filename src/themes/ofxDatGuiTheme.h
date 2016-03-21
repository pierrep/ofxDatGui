/*
    Copyright (C) 2015 Stephen Braitsch [http://braitsch.io]

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once
#include "ofMain.h"
#include "ofxSmartFont.h"

#define RETINA_MIN_WIDTH 2560
#define RETINA_MIN_HEIGHT 1600

inline static bool ofxDatGuiIsRetina()
{
    return (ofGetScreenWidth() >= RETINA_MIN_WIDTH && ofGetScreenHeight() >= RETINA_MIN_HEIGHT);
}

class ofxDatGuiTheme{

    public:
    
    /*
        This is the base class for all custom themes.
        The properites here can be overridden by any class that extends this class.
    */
    
        ofxDatGuiTheme(bool autoInitialize = false)
        {
            if (autoInitialize) init();
        }
    
        void init()
        {
            if (ofxDatGuiIsRetina()){
                font.size *= 2;
                stripe.width *= 2;
                layout.width = 540;
                layout.height *= 2;
                layout.padding *= 2;
                layout.vMargin *= 2;
                layout.iconSize *= 2;
                layout.labelWidth = 190;
                layout.graph.height *=2;
                layout.pad2d.height *=2;
                layout.pad2d.ballSize *=2;
                layout.pad2d.lineWeight *=2;
                layout.matrix.height *=2;
                layout.matrix.buttonSize = 47;
                layout.textInput.highlightPadding *= 2;
            }
            font.ptr = ofxSmartFont::add(font.file, font.size);

            icon.radioOn->load(icon.radioOnPath);
            icon.radioOff->load(icon.radioOffPath);
            icon.dropdown->load(icon.dropdownPath);
            icon.rainbow->load(icon.rainbowPath);
        }
    
    /*
        gui & component colors
    */
    
        struct {
        
        // global gui background color //
            ofColor guiBackground = ofColor::fromHex(0x303030);
        
        // general colors that are shared by all components //
            ofColor label = ofColor::fromHex(0xEEEEEE);
            ofColor icons = ofColor::fromHex(0xEEEEEE);
            ofColor background = ofColor::fromHex(0x1A1A1A);
            ofColor backgroundOnMouseOver = ofColor::fromHex(0x777777);
            ofColor backgroundOnMouseDown = ofColor::fromHex(0x222222);
            ofColor inputAreaBackground = ofColor::fromHex(0x303030);
            
        // component specific colors //
            struct {
                ofColor fill = ofColor::fromHex(0x2FA1D6);
                ofColor text = ofColor::fromHex(0x2FA1D6);
            } slider;
            
            struct {
                ofColor text = ofColor::fromHex(0x00FF00);
                ofColor highlight = ofColor::fromHex(0x688EB5);
                ofColor backgroundOnActive = ofColor::fromHex(0x777777);
            } textInput;
            
            struct {
                ofColor border = ofColor::fromHex(0xEEEEEE);
            } colorPicker;
            
            struct {
                ofColor line = ofColor::fromHex(0xEEEEEE);
                ofColor ball = ofColor::fromHex(0xEEEEEE);
            } pad2d;
            
            struct{
                ofColor lines = ofColor::fromHex(0xEEEEEE);
                ofColor fills = ofColor::fromHex(0xEEEEEE);
            } graph;
            
            struct {
                struct{
                    ofColor label = ofColor::fromHex(0x303030);
                    ofColor button = ofColor::fromHex(0xEEEEEE);
                } normal;
                struct{
                    ofColor label = ofColor::fromHex(0xEEEEEE);
                    ofColor button = ofColor::fromHex(0x2FA1D6);
                } hover;
                struct{
                    ofColor label = ofColor::fromHex(0xEEEEEE);
                    ofColor button = ofColor::fromHex(0x555555);
                } selected;
            } matrix;
            
        } color;
    
    /*
        colored stripes that appear on the left edge of the component
    */
    
        struct {
            int width = 2.0f;
            bool visible = true;
            ofColor label = ofColor::fromHex(0xEEEEEE);
            ofColor button = ofColor::fromHex(0xFFD00B);
            ofColor toggle = ofColor::fromHex(0xFFD00B);
            ofColor slider = ofColor::fromHex(0x2FA1D6);
            ofColor pad2d = ofColor::fromHex(0x9AF398);
            ofColor matrix = ofColor::fromHex(0xB2770D);
            ofColor graph = ofColor::fromHex(0x9AF398);
            ofColor dropdown = ofColor::fromHex(0xC63256);
            ofColor textInput = ofColor::fromHex(0x1ED36F);
            ofColor colorPicker = ofColor::fromHex(0xFFD00B);
        } stripe;
    

    /*
        component border, disabled by default
    */
    
        struct{
            int width = 1.0f;
            bool visible = false;
            ofColor color = hex(0x000000);
        } border;
    
    /*
        layout, sizing and rendering rules
    */
    
        struct {
        
        // general rules that are shared by all components //
            float width = 320.0f;
            float height = 26.0f;
            float padding = 2.0f;
            float vMargin = 1.0f; // vertical spacing between gui components //
            float iconSize = 10.0f;
            float labelWidth = 115.0f;
            float labelMargin = 24.0f;
            float breakHeight = 3.0f;
            bool upperCaseLabels = true;
            
        // component specific rules & settings //
        
            struct {
                int highlightPadding = 5;
                bool forceUpperCase = true;
            } textInput;
        
            struct {
                int height = 82;
                int ballSize = 5;
                int lineWeight = 1;
            } pad2d;
        
            struct {
                int height = 70;
                int pointSize = 2;
                int lineWeight = 2;
            } graph;
        
            struct {
                int height = 82;
                int buttonSize = 27;
            } matrix;
            
        } layout;
    
    /*
        typography & icons
    */
    
        static string AssetPath;
    
        struct {
            int size = 6;
            string file = AssetPath + "ofxbraitsch/fonts/Verdana.ttf";
            shared_ptr<ofxSmartFont> ptr;
        } font;
    
        struct{
            shared_ptr<ofImage> rainbow = make_shared<ofImage>();
            shared_ptr<ofImage> radioOn = make_shared<ofImage>();
            shared_ptr<ofImage> radioOff = make_shared<ofImage>();
            shared_ptr<ofImage> dropdown = make_shared<ofImage>();
            string rainbowPath = AssetPath + "ofxbraitsch/ofxdatgui/picker-rainbow.png";
            string radioOnPath = AssetPath + "ofxbraitsch/ofxdatgui/icon-radio-on.png";
            string radioOffPath = AssetPath + "ofxbraitsch/ofxdatgui/icon-radio-off.png";
            string dropdownPath = AssetPath + "ofxbraitsch/ofxdatgui/icon-dropdown.png";
        } icon;

        static ofColor hex(int n)
        {
            return ofColor::fromHex(n);
        }

};



