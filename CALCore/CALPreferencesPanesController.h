// Based on a classdump from iCal

@interface CALPreferencesPanesController : NSObject
{
    NSWindow *_prefsWindow;
    NSView *_emptyView;
    NSDictionary *_panes;
    int _selectedIndex;
}

- (id)initWithPanes:(id)fp8;
- (void)dealloc;
- (void)show;
- (void)switchToView:(id)fp8;
- (void)resizeWindowToSize:(struct _NSSize)fp8;
- (void)switchPane:(id)fp8;
- (void)switchToPaneWithIdentifier:(id)fp8;
- (void)switchToViewWithIdentifier:(id)fp8;
- (float)toolbarHeight;
- (BOOL)windowShouldClose:(id)fp8;
- (id)window;

@end

@interface CALDotMacSyncPreferences : NSObject
@end

@interface CALNewPreferencesManager : NSObject
{
    CALPreferencesPanesController *_panesController;
    id generalPaneController;
    id backupPaneController;
    id _advancedPaneController;
    CALDotMacSyncPreferences *_dotMacSyncController;
    id formatter;
    BOOL _nibLoaded;
    BOOL _canDisableBirthdaysCalendar;
    int _observingDisabledCount;
    int _cacheNumberOfHours;
    int _cacheStartShownMinute;
    int _cacheShowTimeInMonthView;
}

+ (void)initialize;
+ (id)defaultManager;
- (id)panesController;
- (id)init;
- (void)dealloc;
- (void)disableObserving;
- (void)enableObserving;
- (void)showPrefs:(id)fp8;
- (int)numberOfHoursDisplayed;
- (int)startShownMinute;
- (BOOL)showTimeInMonthView;
- (void)flushCachedPrefs;
- (void)observeValueForKeyPath:(id)fp8 ofObject:(id)fp12 change:(id)fp16 context:(void *)fp20;
- (BOOL)canChooseFirstDayOfWeek;
- (void)setNoValueForPref:(id)fp8;
- (id)objectForPref:(id)fp8;
- (int)integerForPref:(id)fp8;
- (float)floatForPref:(id)fp8;
- (BOOL)boolForPref:(id)fp8;
- (id)stringForPref:(id)fp8;
- (void)setObject:(id)fp8 forPref:(id)fp12;
- (void)setInteger:(int)fp8 forPref:(id)fp12;
- (void)setFloat:(float)fp8 forPref:(id)fp12;
- (void)setBool:(BOOL)fp8 forPref:(id)fp12;
- (void)setString:(id)fp8 forPref:(id)fp12;

@end

