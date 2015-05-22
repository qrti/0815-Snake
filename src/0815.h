// 0815.h 0815 snake V1.0 qrt 160714

#define NUM_DIGITS          10 

// big digit 6 x 11 dots for hh mm ss
#define MAX_DOT             27
#define DOT_WIDTH            5
#define DOT_HIGHT            5
#define RAS_WIDTH            7
#define RAS_HIGHT            7
    
GBitmap *GBtimeDigitDot, *GBdividerHor, *GBdividerVer, *GBdateDigit[NUM_DIGITS];
BitmapLayer *BLdividerHor, *BLdividerVer;

typedef struct{
    int xy[MAX_DOT*2];
    int dots;
}timeDigitChar_struct;

timeDigitChar_struct timeDigitChar[NUM_DIGITS] = {
   {{3, 0, 2, 0, 1, 0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 6,    // 0
     0, 7, 0, 8, 0, 9, 1,10, 2,10, 3,10, 4,10, 5, 9,
     5, 8, 5, 7, 5, 6, 5, 4, 5, 3, 5, 2, 4, 1, 1, 7,
     2, 6, 3, 4, 4, 3}, 27},
     
   {{3, 0, 3, 1, 3, 2, 3, 3, 3, 4, 3, 6, 3, 7, 3, 8,    // 1
     3, 9, 3,10}, 10},
     
   {{0, 0, 1, 0, 2, 0, 3, 0, 4, 1, 5, 2, 5, 3, 4, 4,    // 2
     2, 6, 1, 7, 0, 8, 0, 9, 0,10, 1,10, 2,10, 3,10,
     4,10, 5,10}, 18},
     
   {{0, 0, 1, 0, 2, 0, 3, 0, 4, 1, 5, 2, 5, 3, 5, 4,    // 3
     4, 5, 3, 5, 5, 6, 5, 7, 5, 8, 5, 9, 4,10, 3,10,
     2,10, 1,10, 0,10}, 19},
     
   {{0, 0, 0, 1, 0, 2, 0, 3, 0, 4, 1, 5, 2, 5, 3, 5,    // 4
     4, 5, 5, 2, 5, 3, 5, 4, 5, 6, 5, 7, 5, 8, 5, 9,
     5,10}, 17},
     
   {{0, 1, 0, 2, 0, 3, 0, 4, 1, 5, 2, 5, 3, 5, 4, 6,    // 5
     5, 7, 5, 8, 5, 9, 4,10, 3,10, 2,10, 1,10, 0,10,
     0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0}, 22},
     
   {{4, 0, 3, 0, 2, 0, 1, 0, 0, 1, 0, 2, 0, 3, 0, 4,    // 6
     0, 6, 0, 7, 0, 8, 0, 9, 1,10, 2,10, 3,10, 4,10,
     5, 9, 5, 8, 5, 7, 4, 6, 3, 5, 2, 5, 1, 5}, 23},
     
   {{0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 5, 1, 5, 2,    // 7
     4, 3, 3, 4, 2, 6, 2, 7, 2, 8, 2, 9, 2,10}, 15},
    
   {{3, 0, 2, 0, 1, 0, 0, 1, 0, 2, 0, 3, 0, 4, 1, 5,    // 8
     3, 5, 5, 6, 5, 7, 5, 8, 5, 9, 4,10, 3,10, 2,10,
     1,10, 0, 9, 0, 8, 0, 7, 0, 6, 2, 5, 4, 5, 5, 4,
     5, 3, 5, 2, 4, 1}, 27},
    
   {{3, 0, 2, 0, 1, 0, 0, 1, 0, 2, 0, 3, 0, 4, 1, 5,    // 9
     2, 5, 3, 5, 4, 5, 4, 1, 5, 2, 5, 3, 5, 4, 5, 6,
     5, 7, 5, 8, 5, 9, 4,10, 3,10, 2,10, 1,10}, 23}
};
    
typedef struct{
    BitmapLayer* bilay[MAX_DOT];
    int left, top;
    int last_digit, new_digit, last_dots;
    int phase, i;
}timeDigit_struct;

timeDigit_struct hout = { {},  1,  4, -1, 0, 0, 0, 0 };
timeDigit_struct houo = { {}, 51,  4, -1, 0, 0, 0, 0 };
timeDigit_struct mint = { {},  1, 89, -1, 0, 0, 0, 0 };
timeDigit_struct mino = { {}, 51, 89, -1, 0, 0, 0, 0 };
timeDigit_struct sect = { {},102,  4, -1, 0, 0, 0, 0 };
timeDigit_struct seco = { {},102, 89, -1, 0, 0, 0, 0 };

// images 90° rotated
#define DATEDIGIT_WIDTH      42   
#define DATEDIGIT_HIGHT      25
#define DDL                  143-DATEDIGIT_WIDTH
    
typedef struct{
    BitmapLayer* bilay;
    int left, top;
    int last_digit, new_digit;
    int phase;
}dateDigit_struct;

// dd mm yy / mm dd yy / yy mm dd
dateDigit_struct da0t = { 0, DDL,  0, -1, 0, 0 }; 
dateDigit_struct da0o = { 0, DDL, 27, -1, 0, 0 };  
dateDigit_struct da1t = { 0, DDL, 56, -1, 0, 0 };
dateDigit_struct da1o = { 0, DDL, 84, -1, 0, 0 };
dateDigit_struct da2t = { 0, DDL,113, -1, 0, 0 };
dateDigit_struct da2o = { 0, DDL,141, -1, 0, 0 };

void createGBitmaps()
{
    GBtimeDigitDot = gbitmap_create_with_resource(RESOURCE_ID_TIMEDIGIDOT_BLACK);
    
    GBdividerHor = gbitmap_create_with_resource(RESOURCE_ID_DIVIDERHOR_BLACK);
    GBdividerVer = gbitmap_create_with_resource(RESOURCE_ID_DIVIDERVER_BLACK);
    
    GBdateDigit[0] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT0_BLACK);     // images 90° rotated
    GBdateDigit[1] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT1_BLACK);
    GBdateDigit[2] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT2_BLACK);
    GBdateDigit[3] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT3_BLACK);
    GBdateDigit[4] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT4_BLACK);
    GBdateDigit[5] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT5_BLACK);
    GBdateDigit[6] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT6_BLACK);
    GBdateDigit[7] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT7_BLACK);
    GBdateDigit[8] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT8_BLACK);
    GBdateDigit[9] = gbitmap_create_with_resource(RESOURCE_ID_DATEDIGIT9_BLACK);    
}

void destroyGBitmaps()
{
    gbitmap_destroy(GBtimeDigitDot);
    gbitmap_destroy(GBdividerHor);
    gbitmap_destroy(GBdividerVer);
    
    for(int i=0; i<NUM_DIGITS; i++)
        gbitmap_destroy(GBdateDigit[i]);
}

void createTimeDigitDotBL(timeDigit_struct* t)
{
    Layer* window_layer = window_get_root_layer(window);
        
    for(int i=0; i<MAX_DOT; i++){
        t->bilay[i] = bitmap_layer_create(GRect(0, 0, DOT_WIDTH, DOT_HIGHT));
        bitmap_layer_set_bitmap(t->bilay[i], GBtimeDigitDot);
        //bitmap_layer_set_alignment(t->bilay[i], GAlignTopLeft);
        bitmap_layer_set_compositing_mode(t->bilay[i], inverted ? GCompOpClear : GCompOpOr);
        layer_add_child(window_layer, (Layer*)t->bilay[i]);
        layer_set_hidden((Layer*)t->bilay[i], true);
    }
}

void createDateDigitBL(dateDigit_struct* t)
{
    t->bilay = bitmap_layer_create(GRect(t->left, t->top, DATEDIGIT_WIDTH, DATEDIGIT_HIGHT));    // images 90° rotated
    bitmap_layer_set_alignment(t->bilay, GAlignCenter);
    bitmap_layer_set_compositing_mode(t->bilay, inverted ? GCompOpClear : GCompOpOr);
    layer_add_child(window_get_root_layer(window), (Layer*)t->bilay);
}

void createBarBL(BitmapLayer** b, GBitmap* g, int x, int y)
{
    *b = bitmap_layer_create(GRect(x, y, g->bounds.size.w, g->bounds.size.h));
    bitmap_layer_set_bitmap(*b, g);
    //bitmap_layer_set_alignment(*b, GAlignTopLeft);
    bitmap_layer_set_compositing_mode(*b, inverted ? GCompOpClear : GCompOpOr);
    layer_add_child(window_get_root_layer(window), (Layer*)*b);
    layer_set_hidden((Layer*)*b, !divided);
}

void createBitmapLayers()
{
    createTimeDigitDotBL(&hout);
    createTimeDigitDotBL(&houo);
    createTimeDigitDotBL(&mint);
    createTimeDigitDotBL(&mino);
    
    if(!dispdate){
        createTimeDigitDotBL(&sect);
        createTimeDigitDotBL(&seco);
    }
    else{
        createDateDigitBL(&da0t);
        createDateDigitBL(&da0o);
        createDateDigitBL(&da1t);
        createDateDigitBL(&da1o);
        createDateDigitBL(&da2t);
        createDateDigitBL(&da2o);
    }
    
    createBarBL(&BLdividerHor, GBdividerHor, 0, 83);
    createBarBL(&BLdividerVer, GBdividerVer, 96, 0);
}

void destroyBitmapLayers()
{
    for(int i=0; i<MAX_DOT; i++){
        bitmap_layer_destroy(hout.bilay[i]);
        bitmap_layer_destroy(houo.bilay[i]);
        bitmap_layer_destroy(mint.bilay[i]);
        bitmap_layer_destroy(mino.bilay[i]);
        
        if(!dispdate){
            bitmap_layer_destroy(sect.bilay[i]);
            bitmap_layer_destroy(seco.bilay[i]);
        }
    }
    
    if(dispdate){
        bitmap_layer_destroy(da0t.bilay);
        bitmap_layer_destroy(da0o.bilay);
        bitmap_layer_destroy(da1t.bilay);
        bitmap_layer_destroy(da1o.bilay);
        bitmap_layer_destroy(da2t.bilay);
        bitmap_layer_destroy(da2o.bilay);
    }
    
    bitmap_layer_destroy(BLdividerHor);
    bitmap_layer_destroy(BLdividerVer);
}

void divideDigits()
{
    layer_set_hidden((Layer*)BLdividerHor, !divided);
    layer_set_hidden((Layer*)BLdividerVer, !divided);
}

// phases
#define READY   0
#define HIDE    1
#define SHOW    2
    
bool update = false;
bool ready;

void checkTimeDigit(timeDigit_struct* t, int p)
{
    int digit = buffer[p] - '0';
    
    if(digit != t->last_digit){
        t->new_digit = digit;
        t->phase = HIDE;
        t->i = 0;
    }
}

void checkDateDigit(dateDigit_struct* t, int p)
{
    int digit = buffer[p] - '0';
    
    if(digit != t->last_digit){
        t->new_digit = digit;
        t->phase = HIDE;     
    }
}

int dadi;

void checkDigits()
{
    checkTimeDigit(&hout, 0);
    checkTimeDigit(&houo, 1);
    checkTimeDigit(&mint, 2);
    checkTimeDigit(&mino, 3);
    
    if(!dispdate){
        checkTimeDigit(&sect, 4);
        checkTimeDigit(&seco, 5);
    }
    else{
        checkDateDigit(&da0t, 6);
        checkDateDigit(&da0o, 7);
        checkDateDigit(&da1t, 8);
        checkDateDigit(&da1o, 9);    
        checkDateDigit(&da2t, 10);
        checkDateDigit(&da2o, 11);  
        dadi = -1;       
    }
    
    update = true;
}

void updateTimeDigit(timeDigit_struct* t)
{
    if(t->phase == SHOW){
        int i = t->i << 1;
        int d = t->new_digit;
        
        layer_set_frame((Layer*)t->bilay[t->i], GRect(t->left + timeDigitChar[d].xy[i]   * RAS_WIDTH, 
                                                      t->top  + timeDigitChar[d].xy[i+1] * RAS_HIGHT, 
                                                      DOT_WIDTH, DOT_HIGHT));
        
        layer_set_hidden((Layer*)t->bilay[t->i++], false);
        
        if(t->i >= t->last_dots){
            t->last_digit = d;
            t->phase = READY;
        }
        else{
            ready = false;
        }
    }
    else{
        for(int i=0; i<t->last_dots; i++)
            layer_set_hidden((Layer*)t->bilay[i], true);
           
        t->last_dots = timeDigitChar[t->new_digit].dots;
        t->phase = SHOW;
        ready = false;
    }   
}

void updateDateDigit(dateDigit_struct* t)
{
    if(dadi == -1){
        if(da0t.phase == HIDE)
            bitmap_layer_set_bitmap(da0t.bilay, NULL);
        
        if(da0o.phase == HIDE)
            bitmap_layer_set_bitmap(da0o.bilay, NULL);
        
        if(da1t.phase == HIDE)
            bitmap_layer_set_bitmap(da1t.bilay, NULL);
        
        if(da1o.phase == HIDE)
            bitmap_layer_set_bitmap(da1o.bilay, NULL);
        
        if(da2t.phase == HIDE)
            bitmap_layer_set_bitmap(da2t.bilay, NULL);
        
        if(da2o.phase == HIDE)
            bitmap_layer_set_bitmap(da2o.bilay, NULL);        
    }
    else{
        if(dadi == 0){
            bitmap_layer_set_bitmap(t->bilay, GBdateDigit[t->new_digit]);
        }
        else if(dadi == 5){
            t->last_digit = t->new_digit;
            t->phase = READY;
            dadi = -1;
        }       
    }
    
    dadi++;
    ready = false;
}

void updateDigits()
{        
    ready = true;
    
    if(hout.phase != READY) 
        updateTimeDigit(&hout);
 
    if(houo.phase != READY) 
        updateTimeDigit(&houo);
    
    if(mint.phase != READY) 
        updateTimeDigit(&mint);
 
    if(mino.phase != READY) 
        updateTimeDigit(&mino);

    if(!dispdate){
        if(sect.phase != READY) 
            updateTimeDigit(&sect);
     
        if(seco.phase != READY) 
            updateTimeDigit(&seco);
    }
    else{
        if(da0t.phase != READY)
            updateDateDigit(&da0t);
        else if(da0o.phase != READY)
            updateDateDigit(&da0o);
        else if(da1t.phase != READY)
            updateDateDigit(&da1t);
        else if(da1o.phase != READY)
            updateDateDigit(&da1o);
        else if(da2t.phase != READY)
            updateDateDigit(&da2t);
        else if(da2o.phase != READY)
            updateDateDigit(&da2o);
    }
    
    update = !ready;
}

void dirtyDigits()
{
    hout.last_digit = -1;
    houo.last_digit = -1;
    mint.last_digit = -1;
    mino.last_digit = -1;
    
    if(!dispdate){
        sect.last_digit = -1;
        seco.last_digit = -1;
    }
    else{
        da0t.last_digit = -1;
        da0o.last_digit = -1;
        da1t.last_digit = -1;
        da1o.last_digit = -1;
        da2t.last_digit = -1;
        da2o.last_digit = -1;
    }
}

void setDateForm()
{
    if(dateform == 1)
        strcpy(tidafo, "%H%M%S%m%d%y");
    else if(dateform == 2)
        strcpy(tidafo, "%H%M%S%y%m%d");
    else
        strcpy(tidafo, "%H%M%S%d%m%y");
}















