/***************************************************************
 * Name:      FacEMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Morgan ()
 * Created:   2016-05-09
 * Copyright: Morgan ()
 * License:
 **************************************************************/

//audio headers

#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
using namespace std;


#include "gui.hpp"
#include <wx/msgdlg.h>

//(*InternalHeaders(FacEFrame)
#include <wx/intl.h>
#include <wx/string.h>

//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(FacEFrame)
const long FacEFrame::ID_BUTTON1 = wxNewId();
const long FacEFrame::ID_BUTTON2 = wxNewId();
const long FacEFrame::ID_BUTTON3 = wxNewId();
const long FacEFrame::ID_BUTTON11 = wxNewId();
const long FacEFrame::ID_BUTTON22 = wxNewId();
const long FacEFrame::ID_BUTTON33 = wxNewId();
const long FacEFrame::ID_BUTTON111 = wxNewId();
const long FacEFrame::ID_BUTTON222 = wxNewId();
const long FacEFrame::ID_BUTTON333 = wxNewId();
const long FacEFrame::ID_BUTTON1111 = wxNewId();
const long FacEFrame::ID_BUTTON2222 = wxNewId();
const long FacEFrame::ID_BUTTON3333 = wxNewId();
const long FacEFrame::ID_PANEL1 = wxNewId();
const long FacEFrame::ID_MENUITEM1 = wxNewId();
const long FacEFrame::idMenuAbout = wxNewId();
const long FacEFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FacEFrame,wxFrame)
    //(*EventTable(FacEFrame)
    //*)
END_EVENT_TABLE()

FacEFrame::FacEFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(FacEFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(152,96), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Career"), wxPoint(0,0), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Family"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(Button2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Relationships"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer1->Add(Button3, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    Button11 = new wxButton(Panel1, ID_BUTTON11, _("Happy with Career"), wxPoint(0,0), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    BoxSizer1->Add(Button11, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Button11->Hide();
    Button22 = new wxButton(Panel1, ID_BUTTON22, _("Happy with Family"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON22"));
    BoxSizer1->Add(Button22, 1, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, 5);
    Button22->Hide();
    Button33 = new wxButton(Panel1, ID_BUTTON33, _("Happy with Relationships"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON33"));
    BoxSizer1->Add(Button33, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Button33->Hide();
    Button111 = new wxButton(Panel1, ID_BUTTON111, _("Disgusted with Career"), wxPoint(0,0), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON111"));
    BoxSizer1->Add(Button111, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Button111->Hide();
    Button222 = new wxButton(Panel1, ID_BUTTON222, _("Disgusted with Family"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON222"));
    BoxSizer1->Add(Button222, 1, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, 5);
    Button222->Hide();
    Button333 = new wxButton(Panel1, ID_BUTTON333, _("Disgusted with Relationships"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON333"));
    BoxSizer1->Add(Button333, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Button333->Hide();
    Button1111 = new wxButton(Panel1, ID_BUTTON1111, _("Surprised with Career"), wxPoint(0,0), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1111"));
    BoxSizer1->Add(Button1111, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Button1111->Hide();
    Button2222 = new wxButton(Panel1, ID_BUTTON2222, _("Suprised with Family"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2222"));
    BoxSizer1->Add(Button2222, 1, wxALL|wxALIGN_RIGHT|wxALIGN_TOP, 5);
    Button2222->Hide();
    Button3333 = new wxButton(Panel1, ID_BUTTON3333, _("Surprised with Relationships"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3333"));
    BoxSizer1->Add(Button3333, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    Button3333->Hide();
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FacEFrame::OnButtonSelect);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FacEFrame::OnButtonSelect);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FacEFrame::OnButtonSelect);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&FacEFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&FacEFrame::OnAbout);
    //*)
}

FacEFrame::~FacEFrame()
{
    //(*Destroy(FacEFrame)
    //*)
}

void FacEFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void FacEFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "To navigate through the FacE GUI first signify your emotional sate \nThe three options are happy, disgust, and surprise \nYou then navigate to a subject topic through your eye movements \nThis will output a spoken sentence correlating to your emotional state and the subject chosen";
    wxMessageBox(msg, _("Welcome to FacE"));
}

int FacEFrame::OnButtonSelect(wxCommandEvent& event)
{
 //Used int face and eye inputs to test button outputs
 //int face = 0; //0=happy, 1=disgust, 2=relationships
 //int eye = 2; //0=career, 1=family, 2=relationships
 int buttonselection;
        switch(face) {
            case 0:// happy
                Button1->Hide();
                Button2->Hide();
                Button3->Hide();
                Button11->Show();
                Button22->Show();
                Button33->Show();
                switch(eye){
                    case 0:
                        Button22->Hide();
                        Button33->Hide();
                        Button11->Show();
                        buttonselection=0;
                    break;
                    case 1:
                        Button11->Hide();
                        Button33->Hide();
                        Button22->Show();
                        buttonselection=1;
                    break;
                    case 2:
                        Button11->Hide();
                        Button22->Hide();
                        Button33->Show();
                        buttonselection=2;
                    break;
                    default:
                        std::cout << "Select a button" << endl;
                    break;
                }
        break;
            case 1: // disgust
                Button1->Hide();
                Button2->Hide();
                Button3->Hide();
                Button11->Hide();
                Button22->Hide();
                Button33->Hide();
                Button111->Show();
                Button222->Show();
                Button333->Show();
                switch(eye){
                    case 0:
                        Button222->Hide();
                        Button333->Hide();
                        Button111->Show();
                        buttonselection=3;
                    break;
                    case 1:
                        Button111->Hide();
                        Button333->Hide();
                        Button222->Show();
                        buttonselection=4;
                    break;
                    case 2:
                        Button111->Hide();
                        Button222->Hide();
                        Button333->Show();
                        buttonselection=5;
                    break;
                    default:
                        std::cout << "Select a button" << endl;
                    break;
            break;
			}
            case 2: // surprised
                Button1->Hide();
                Button2->Hide();
                Button3->Hide();
                Button11->Hide();
                Button22->Hide();
                Button33->Hide();
                Button111->Hide();
                Button222->Hide();
                Button333->Hide();
                Button1111->Show();
                Button2222->Show();
                Button3333->Show();
                switch (eye){
                    case 0:
                        Button3333->Hide();
                        Button2222->Hide();
                        Button1111->Show();
                        buttonselection=6;
                    break;
                    case 1:
                        Button1111->Hide();
                        Button3333->Hide();
                        Button2222->Show();
                        buttonselection=7;
                    break;
                    case 2:
                        Button1111->Hide();
                        Button2222->Hide();
                        Button3333->Show();
                        buttonselection=8;
                    break;
                    default:
                        std::cout << "Select a button" << endl;
                        break;
                }

            default:
               std::cout << "Make a selection with facial expression" << endl;
            break;

            }
  return buttonselection;

}

void playSound(int buttonselection)
{

    switch(buttonselection){
	case 0:
	{
		// Load a sound buffer from any sound file
   		sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound00.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
		playSound();
		break;
	}
	case 1:
	{	// Load a sound buffer from any sound file
   	 	sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound02.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
	playSound();
	break;
	}

	case 2:
	{	// Load a sound buffer from any sound file
   		sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound01.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
	playSound();
	break;
	}

	case 3:
	{	// Load a sound buffer from any sound file
   		sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound03.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
	playSound();
	break;
	}

	case 4:
	{	// Load a sound buffer from any sound file
   		sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound05.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
	playSound();
	break;
	}

	case 5:
	{	// Load a sound buffer from any sound file
   		sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound04.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
	playSound();
	break;
	}
	case 6:
	{	// Load a sound buffer from any sound file
   		sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound06.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
	playSound();
	break;
	}
	case 7:
	{	// Load a sound buffer from any sound file
   		sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound08.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
	playSound();
	break;
	}

	case 8:
		// Load a sound buffer from any sound file
   		sf::SoundBuffer buffer;
    		if (!buffer.loadFromFile("Sound07.wav")) //in current directory
        	return;


    		// Create a sound instance and play it
    		sf::Sound sound(buffer);
    		sound.play();

    		// Loop while the sound is playing
    		while (sound.getStatus() == sf::Sound::Playing)
    		{
        		// how quickly the playing time is updated
        		sf::sleep(sf::milliseconds(100));

        		// Display playing time <--- not necessary but works better
			// with this for some reason
        		std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        		std::cout << std::flush;
    		}
    		std::cout << std::endl << std::endl;
	playSound();
	break;

	/*default:
		std::cout << "something went wrong with choosing correct audio file" << endl;
            break; */
	}
}

/*int main()
{
    // Play sound
    playSound();

    return EXIT_SUCCESS;
} */





        
    
