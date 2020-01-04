/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_VIEWTOMAINMENU_H
#define GAMEHEXXAGON_VIEWTOMAINMENU_H


#include <SFMLComponents/WindowViews/WindowView.h>

/**
 * interface to Mainmenu used by ViewHandler
 */
class ViewToMainmenu: public WindowView {
public:
    /**
     * called by ViewHandler to update Mainmenu
     * @param isConnected bool is true when connected to server, else false
     */
    virtual void display(bool isConnected) = 0;
};


#endif //GAMEHEXXAGON_VIEWTOMAINMENU_H
