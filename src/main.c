// main.c 0815 snake V1.0 qrt 160714

#include <pebble.h>

#define KEY_DISPDATE      0 
#define KEY_DIVIDE        1
#define KEY_INVERT        2
#define KEY_DATEFORM      3
    
Window *window;
AppTimer* timer;

char buffer[] = "HHMMSSddmmyy";
char tidafo[12+1];

bool inverted, divided, dispdate;
int dateform;
    
#include "0815.h"

void timer_callback(void *data) 
{	
    if(update){
        updateDigits();
        timer = app_timer_register(20, (AppTimerCallback)timer_callback, NULL);
    }
}    

bool setMinuteTicks;
    
void tick_handler(struct tm *tick_time, TimeUnits units_changed)
{
	if(!update){
        strftime(buffer, 12+1, tidafo, tick_time);
        checkDigits();
        timer = app_timer_register(1, (AppTimerCallback)timer_callback, NULL);
        
        if(setMinuteTicks){
            tick_timer_service_subscribe(MINUTE_UNIT, (TickHandler)tick_handler);
            setMinuteTicks = false;
        }
    }
}

void in_recv_handler(DictionaryIterator *iter, void *context)
{
    Tuple *dispdate_tuple = dict_find(iter, KEY_DISPDATE);
    Tuple *divide_tuple = dict_find(iter, KEY_DIVIDE);
    Tuple *invert_tuple = dict_find(iter, KEY_INVERT);
    Tuple *dateform_tuple = dict_find(iter, KEY_DATEFORM);
    
    if(dispdate_tuple){   
        int v = -1;
        
        if(strcmp(dispdate_tuple->value->cstring, "on") == 0)
            v = true;
        else if(strcmp(dispdate_tuple->value->cstring, "off") == 0)
            v = false;
        
        if(v!=-1 && v!=dispdate){
            persist_write_bool(KEY_DISPDATE, v);
            destroyBitmapLayers();
            dispdate = v;
            createBitmapLayers();
            tick_timer_service_subscribe(SECOND_UNIT, (TickHandler)tick_handler);
            setMinuteTicks = dispdate;
        }
    }    

    if(divide_tuple){   
        int v = -1;
        
        if(strcmp(divide_tuple->value->cstring, "on") == 0)
            v = true;
        else if(strcmp(divide_tuple->value->cstring, "off") == 0)
            v = false;

        if(v!=-1 && v!=divided){
            divided = v;
            persist_write_bool(KEY_DIVIDE, divided);
            divideDigits();
        }
    }   
    
    if(invert_tuple){
        int v = -1;
        
        if(strcmp(invert_tuple->value->cstring, "on") == 0)
            v = true;
        else if(strcmp(invert_tuple->value->cstring, "off") == 0)
            v = false;

        if(v!=-1 && v!=inverted){
            persist_write_bool(KEY_INVERT, v);
            destroyBitmapLayers();
            inverted = v;
            createBitmapLayers();  
            window_set_background_color(window, inverted ? GColorWhite : GColorBlack);
        }
    }
    
    if(dateform_tuple){
        dateform = atoi(dateform_tuple->value->cstring);
        setDateForm(); 
        tick_timer_service_subscribe(SECOND_UNIT, (TickHandler)tick_handler);
        setMinuteTicks = dispdate;
    }
        
    dirtyDigits();
}

void window_load(Window *window)
{
    createGBitmaps();
    createBitmapLayers();
        
    //timer = app_timer_register(1000, (AppTimerCallback)timer_callback, NULL);  
    
    //struct tm *t;
    //time_t temp;
    //temp = time(NULL);
    //t = localtime(&temp);
    //tick_handler(t, HOUR_UNIT|MINUTE_UNIT|SECOND_UNIT);     // manually call the tick handler
}

void window_unload(Window *window)
{
    destroyBitmapLayers();
    destroyGBitmaps();
    
    //if(timer != NULL) 
    //    app_timer_cancel(timer);
}

void init()
{
    window = window_create();
    
    window_set_window_handlers(window, (WindowHandlers){
        .load = window_load,
        .unload = window_unload,
    });
    
    app_message_register_inbox_received((AppMessageInboxReceived) in_recv_handler);
    app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
    
    dispdate = persist_read_bool(KEY_DISPDATE);
    divided = persist_read_bool(KEY_DIVIDE);
    inverted = persist_read_bool(KEY_INVERT);
    dateform = persist_read_int(KEY_DATEFORM);
    
    setMinuteTicks = dispdate;
    setDateForm();
    
    window_set_background_color(window, inverted ? GColorWhite : GColorBlack);
    window_stack_push(window, true);
    
    tick_timer_service_subscribe(SECOND_UNIT, (TickHandler)tick_handler);
}

void deinit()
{
    tick_timer_service_unsubscribe();
    window_destroy(window);
}

int main(void)
{
    init();
    app_event_loop();
    deinit();
}

// APP_LOG(APP_LOG_LEVEL_DEBUG, "DIVIDE");













