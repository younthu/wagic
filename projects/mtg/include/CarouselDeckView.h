#ifndef _CAROUSEL_DECK_VIEW_H_
#define _CAROUSEL_DECK_VIEW_H_

#include "DeckView.h"
#include "Easing.h"

class CarouselDeckView : public DeckView
{
private:
    static const float max_scale;
    static const float x_center;
    static const float right_border;
    static const float slide_animation_duration;
    static const float scroll_animation_duration;

public:
    CarouselDeckView();
    virtual ~CarouselDeckView();
    void Reset();

    void UpdateViewState(float dt);
    void UpdateCardPosition(int index);
    void renderCard(int index)
    {
        int alpha = (int) (255 * (mCards[index].scale + 1.0 - max_scale));
        DeckView::renderCard(index, alpha);
    }

    void Render();

    bool ButtonPressed(Buttons button);
    MTGCard * Click(int x, int y);
    MTGCard * Click();

    void changePositionAnimated(int offset);
    void changeFilterAnimated(int offset);

    MTGCard *getActiveCard();
private:
    float mScrollOffset, mSlideOffset;
    InOutQuadEasing mScrollEasing;
    InOutQuadEasing mSlideEasing;
};

#endif //_CAROUSEL_DECK_VIEW_H_
