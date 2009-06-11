// Most of this info is a classdump from /System/Library/PrivateFrameworks/CALCore.framework
// Simply stripped down to let us focus on the items we're interested in

@interface BMBeveledButton : NSObject
@end
@interface BMiTunesButton : NSObject
@end
@interface CALMainCalendarView : NSObject
@end
@interface BMTabControl : NSObject
@end
@interface CALPaned : NSObject
@end
@interface CALSwapView : NSObject
@end
@interface CALSearchView : NSObject
@end
@interface CALMiniMonthlyView : NSObject
@end
@interface CALNewInspector : NSObject
@end
@interface CALLayerManager : NSObject
@end
@interface CALSelectionManager : NSObject
@end
@interface CALHeaderedView : NSObject
@end
@interface CALTaskManager : NSObject
@end
@interface CALCalendarSource : NSObject
@end
@interface CALDate : NSObject
@end
@interface CALDateTime : NSObject
@end

@interface CALPropertyValue : NSObject <NSCoding>
{
    NSMutableDictionary *_params;
    int _type;
    id _value;
    NSMutableDictionary *_changelist;
    int _oldtype;
    id _oldvalue;
    int _status;
}

+ (id)propertyValue;
+ (id)propertyValueWithValue:(id)fp8;
+ (id)propertyValueWithValue:(id)fp8 withType:(int)fp12;
- (id)description;
- (BOOL)isEqualToPropertyValue:(id)fp8;
- (BOOL)isEqualToPropertyValue:(id)fp8 ignoreParameters:(id)fp12;
- (void)encodeWithCoder:(id)fp8;
- (id)initWithCoder:(id)fp8;
- (id)init;
- (id)initWithValue:(id)fp8;
- (id)initWithValue:(id)fp8 withType:(int)fp12;
- (void)dealloc;
- (void)addParameters:(id)fp8;
- (void)addParameter:(id)fp8 withValue:(id)fp12;
- (void)removeParameter:(id)fp8;
- (id)parameterValueForName:(id)fp8;
- (BOOL)hasParameter:(id)fp8;
- (int)type;
- (id)value;
- (id)setValue:(id)fp8 withType:(int)fp12;
- (id)parameters;
- (id)stringValue;
- (BOOL)dirty;
- (int)commitStatus;
- (void)setCommitStatus:(int)fp8;
- (void)markAsClean;
- (void)setParameters:(id)fp8;
- (void)computeUndo;
- (void)restoreAsClean;
- (id)copyWithZone:(struct _NSZone *)fp8;

@end

@interface CALDuration : NSObject
{
    double _duration;
}

+ (id)durationWithDays:(int)fp8;
+ (id)durationWithHours:(int)fp8;
+ (id)durationWithMinutes:(int)fp8;
+ (id)durationWithSeconds:(int)fp8;
+ (id)durationWithDays:(int)fp8 hours:(int)fp12;
+ (id)durationWithDays:(int)fp8 hours:(int)fp12 minutes:(int)fp16;
+ (id)durationWithDays:(int)fp8 hours:(int)fp12 minutes:(int)fp16 seconds:(int)fp20;
+ (id)durationWithDurationRoundedToDay:(id)fp8;
+ (id)durationWithDurationWithoutDayPart:(id)fp8;
+ (id)durationWithRawInterval:(double)fp8;
- (void)encodeWithCoder:(id)fp8;
- (id)initWithCoder:(id)fp8;
- (id)description;
- (id)initWithDays:(int)fp8;
- (id)initWithHours:(int)fp8;
- (id)initWithMinutes:(int)fp8;
- (id)initWithSeconds:(int)fp8;
- (id)initWithDays:(int)fp8 hours:(int)fp12;
- (id)initWithDays:(int)fp8 hours:(int)fp12 minutes:(int)fp16;
- (id)initWithDays:(int)fp8 hours:(int)fp12 minutes:(int)fp16 seconds:(int)fp20;
- (id)initWithDurationRoundedToDay:(id)fp8;
- (id)initWithDurationWithoutDayPart:(id)fp8;
- (id)durationRoundedToDay;
- (id)initWithRawInterval:(double)fp8;
- (double)rawInterval;
- (void)setRawInterval:(double)fp8;
- (int)daysPart;
- (int)hoursPart;
- (int)minutesPart;
- (int)secondsPart;
- (BOOL)isEqual:(id)fp8;
- (BOOL)isEqualTo:(id)fp8;
- (BOOL)isLongerThan:(id)fp8;
- (BOOL)isNegative;
- (void)inverse;
- (id)copyWithZone:(struct _NSZone *)fp8;

@end

@interface CALAlarmTrigger : CALPropertyValue
{
}

+ (id)trigger;
+ (id)triggerWithDate:(id)fp8;
+ (id)triggerWithDuration:(id)fp8;
+ (id)triggerWithDuration:(id)fp8 withRelation:(int)fp12;
- (id)initWithDate:(id)fp8;
- (id)initWithDuration:(id)fp8;
- (id)initWithDuration:(id)fp8 withRelation:(int)fp12;
- (id)description;
- (BOOL)isDurationBased;
- (int)relation;
- (void)setRelation:(int)fp8;
- (id)date;
- (id)setDate:(id)fp8;
- (id)duration;
- (id)setDuration:(id)fp8;
- (id)signature;

@end


@interface CALProperty : NSObject <NSCoding>
{
    NSString *_name;
    NSMutableArray *_values;
    NSMutableArray *_changelist;
    int _status;
}

+ (id)propertyWithName:(id)fp8 withValue:(id)fp12;
+ (id)propertyWithName:(id)fp8 withValue:(id)fp12 withType:(int)fp16;
+ (id)propertyWithName:(id)fp8 withValues:(id)fp12 withType:(int)fp16;
+ (id)propertyWithName:(id)fp8 withPropertyValue:(id)fp12;
+ (id)propertyWithName:(id)fp8 withPropertyValues:(id)fp12;
- (id)description;
- (void)encodeWithCoder:(id)fp8;
- (id)initWithCoder:(id)fp8;
- (id)initWithName:(id)fp8;
- (id)initWithName:(id)fp8 withValue:(id)fp12;
- (id)initWithName:(id)fp8 withValue:(id)fp12 withType:(int)fp16;
- (id)initWithName:(id)fp8 withValues:(id)fp12 withType:(int)fp16;
- (id)initWithName:(id)fp8 withPropertyValue:(id)fp12;
- (id)initWithName:(id)fp8 withPropertyValues:(id)fp12;
- (void)dealloc;
- (void)setSingleValue:(id)fp8;
- (void)addValue:(id)fp8;
- (void)removeValue:(id)fp8;
- (id)values;
- (id)name;
- (id)singleValue;
- (BOOL)isSingleValued;
- (unsigned int)count;
- (int)commitStatus;
- (void)setCommitStatus:(int)fp8;
- (BOOL)isEqualToProperty:(id)fp8;
- (BOOL)isEqualToProperty:(id)fp8 ignoreParameters:(id)fp12;
- (BOOL)dirty;
- (void)markAsClean;
- (void)restoreAsClean;
- (void)computeUndo;
- (id)copyWithZone:(struct _NSZone *)fp8;
- (id)stringValue;

@end




@interface CALAbstractEntity : NSObject <NSCoding>
{
    NSMutableDictionary *_properties;
    NSMutableArray *_subcomponents;
    CALCalendarSource *_originRepository;
    id _privateID;
    NSMutableDictionary *_changelist;
    NSMutableArray *_subcomponentschangelist;
    int _status;
    int _commitcount;
}

- (id)init;
- (id)description;
- (void)encodeWithCoder:(id)fp8;
- (id)initWithCoder:(id)fp8;
- (void)registerUndoCommit;
- (void)removeProperty:(id)fp8;
- (void)setProperty:(id)fp8;
- (BOOL)hasProperty:(id)fp8;
- (void)addPropertyValue:(id)fp8 withValue:(id)fp12;
- (void)removePropertyValue:(id)fp8 forName:(id)fp12;
- (CALProperty*)propertyForName:(NSString*)name;
- (void)_setProperties:(id)fp8;
- (void)setProperties:(id)fp8;
- (id)properties;
- (id)checkValidity;
- (void)actualCommitWithUndo:(BOOL)fp8;
- (void)actualCommit;
- (void)commit;
- (void)unregisterFromUndo;
- (BOOL)detached;
- (void)deleteFromRepository;
- (id)repository;
- (void)setRepository:(id)fp8;
- (void)moveToRepository:(id)fp8;
- (BOOL)isEqual:(id)fp8;
- (BOOL)isEqualToEntity:(id)fp8;
- (void)computeUndo;
- (BOOL)hasDirtySubcomponent;
- (BOOL)hasDirtyProperty:(id)fp8;
- (id)_dirtyPropertiesNames;
- (id)deletedProperties;
- (id)dirtyProperties;
- (BOOL)hasDirtyPropertyAmong:(id)fp8;
- (void)restoreAsClean;
- (void)markAsClean;
- (BOOL)dirty;
- (int)commitStatus;
- (void)setCommitStatus:(int)fp8;
- (BOOL)hasPrivateID;
- (id)privateID;
- (void)dealloc;
- (void)reset;
- (void)addSubComponent:(id)fp8;
- (void)removeSubComponent:(id)fp8;
- (id)subComponents;
- (void)copyPropertiesFrom:(id)fp8;
- (id)copyWithZone:(struct _NSZone *)fp8;
- (void)removeAllPropertiesWithKeys:(id)fp8;
- (void)keepOnlyPropertiesWithKeys:(id)fp8;
- (void)removeAllSubComponentsOfClasses:(id)fp8;
- (void)keepOnlySubComponentsOfClasses:(id)fp8;
- (Class)correspondingOccurrenceClass;

@end

@interface CALOccurrableEntity : CALAbstractEntity
{
}

- (id)expandOnTimeRange:(id)fp8;
- (id)createOccurrenceForStartDate:(id)fp8;
- (id)getOccurrenceForStartDate:(id)fp8;

@end


@interface CALEntity : CALOccurrableEntity
{
    CALEntity *_parentEntity;
    NSMutableArray *_children;
    BOOL _hasReccurrence;
    CALDate *_eventCachedStartDate;
    CALDate *_cachedEndDate;
    NSDictionary *_searchHackDict;
}

- (id)init;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)fp8;
- (Class)correspondingOccurrenceClass;
- (void)cleanUp;
- (void)removeProperty:(id)fp8;
- (void)invalidateEntityCaches;
- (void)markAsClean;
- (void)computeUndo;
- (BOOL)dirty;
- (id)repository;
- (void)setRepository:(id)fp8;
- (void)commitWithoutBump;
- (void)commit;
- (id)uid;
- (void)setUID:(id)fp8;
- (void)setUIDForMainAndDetached:(id)fp8;
- (void)validateIDs;
- (id)summary;
- (void)setSummary:(id)fp8;
- (id)templateData;
- (void)setTemplateData:(id)fp8;
- (id)cancelItemID;
- (void)setCancelItemID:(id)fp8;
- (id)iconInformation;
- (void)setIconInformation:(id)fp8;
- (id)invitationUID;
- (void)removeInvitationUID;
- (void)setInvitationUID:(id)fp8;
- (id)invitationUIDorUID;
- (BOOL)hasInvitationUID;
- (BOOL)shouldPushInvitationUID;
- (void)adoptInvitationUID:(id)fp8;
- (id)comment;
- (void)setComment:(id)fp8;
- (id)desc;
- (void)setDesc:(id)fp8;
- (int)status;
- (void)setStatus:(int)fp8;
- (void)forceDatesToGMT;
- (id)startDate;
- (void)setStartDate:(id)fp8;
- (int)classification;
- (void)setClassification:(int)fp8;
- (id)url;
- (void)setURL:(id)fp8;
- (id)creationDate;
- (void)setCreationDate:(id)fp8;
- (id)lastModificationDate;
- (void)setLastModificationDate:(id)fp8;
- (id)stampDate;
- (void)setStampDate:(id)fp8;
- (void)setSequence:(int)fp8;
- (int)sequence;
- (void)incrementSequence;
- (id)alarms;
- (id)alarmWithSignature:(id)fp8;
- (BOOL)hasAlarms;
- (void)setAlarmsOriginEntity;
- (BOOL)hasOrganizerNoInherit;
- (id)organizerNoInherit;
- (void)setOrganizerNoInherit:(id)fp8;
- (BOOL)hasOrganizer;
- (id)organizer;
- (void)setOrganizer:(id)fp8;
- (void)removeOrganizer;
- (BOOL)hasAttendeesNoInherit;
- (id)attendeesNoInherit;
- (BOOL)hasAttendees;
- (id)attendees;
- (void)addAttendee:(id)fp8;
- (BOOL)hasAttendee:(id)fp8;
- (void)removeAttendee:(id)fp8;
- (BOOL)hasSendableAttendees;
- (void)setAttendeesHack:(id)fp8;
- (void)setAttendees:(id)fp8;
- (void)removeAllAttendees;
- (BOOL)invitationStatusPending;
- (void)resetParticipationStatus;
- (id)relatedTos;
- (void)addRelatedTo:(id)fp8;
- (void)setRelatedTos:(id)fp8;
- (void)removeAllRelatedTos;
- (void)removeRelatedTo:(id)fp8;
- (id)categories;
- (void)addCategory:(id)fp8;
- (void)setCategories:(id)fp8;
- (void)removeAllCategories;
- (void)removeCategory:(id)fp8;
- (id)attachments;
- (void)addAttachment:(id)fp8;
- (void)removeAttachment:(id)fp8;
- (void)removeAllAttachments;
- (void)addAlarm:(id)fp8;
- (void)removeAlarm:(id)fp8;
- (void)removeAllAlarms;
- (void)setMyiTIPStatusChanged:(BOOL)fp8;
- (BOOL)hasMyiTIPStatusChanged;
- (BOOL)myiTIPStatusChanged;
- (void)setAlreadySentMarker:(BOOL)fp8;
- (BOOL)alreadySentMarker;
- (void)setRSVPNeeded:(BOOL)fp8;
- (BOOL)rsvpNeeded;
- (void)_setITipNeedsUpd:(BOOL)fp8;
- (BOOL)_ITipNeedsUpd;
- (id)upperBoundDate;
- (id)occurrencesFromDates:(id)fp8;
- (id)expandOnTimeRange:(id)fp8;
- (id)mainOccurrenceID;
- (id)getMainOccurrence;
- (int)compare:(id)fp8;
- (id)versionForVersionTag:(id)fp8;
- (id)versions;

@end


@interface CALEvent : CALEntity
{
    CALDate *_eventCachedEndDate;
    CALDateTime *_alldaycacheStart;
    CALDateTime *_alldaycacheEnd;
    NSTimeZone *_alldaycacheTimeZone;
}

+ (id)event;
- (Class)correspondingOccurrenceClass;
- (void)dealloc;
- (void)invalidateOccurrenceCaches;
- (void)invalidateEntityCaches;
- (void)actualCommitWithUndo:(BOOL)fp8;
- (void)actualCommit;
- (void)forceDatesToGMT;
- (id)endDate;
- (void)setEndDate:(id)fp8;
- (void)releaseCachedEndDate;
- (id)duration;
- (void)setDuration:(id)fp8;
- (void)moveToStartDate:(id)fp8;
- (void)setStartDate:(id)fp8;
- (void)setFullDayEvent:(BOOL)fp8;
- (void)setFullDayEvent:(BOOL)fp8 withHintTimeRange:(id)fp12;
- (BOOL)isFullDayEvent;
- (int)priority;
- (void)removePriority;
- (void)setPriority:(int)fp8;
- (int)transparency;
- (void)setTransparency:(int)fp8;
- (id)location;
- (void)setLocation:(id)fp8;
- (void)cleanUp;
- (id)checkValidity;
- (id)upperBoundDate;
- (id)expandOnTimeRange:(id)fp8;

@end

@interface CALAlarm : CALOccurrableEntity
{
    CALEntity *_originEntity;
}

- (Class)correspondingOccurrenceClass;
- (id)initWithTrigger:(CALAlarmTrigger*)trigger;
- (id)copyWithZone:(struct _NSZone *)fp8;
- (void)setActionPropertyHackForiSync11:(int)fp8;
- (id)duration;
- (int)repeat;
- (id)setDuration:(id)fp8 withRepeat:(int)fp12;
- (void)markTriggerAsModified;
- (CALAlarmTrigger*)trigger;
- (id)setTrigger:(id)fp8;
- (id)originEntity;
- (void)setOriginEntity:(id)fp8;
- (id)upperBoundDate;
- (id)expandOnTimeRange:(id)fp8;
- (id)uid;
- (id)signature;
- (id)alarmUID;
- (void)setAlarmUID:(id)fp8;
- (id)occurrenceTriggers;
- (id)triggerForOccurrenceDateID:(id)fp8;
- (void)removeAllOccurrenceTriggers;
- (void)addOccurrenceTrigger:(id)fp8;
- (void)triggerDate:(id)fp8 forOccurrenceDateID:(id)fp12;
- (void)removeOccurrenceTriggerForOccurrenceDateID:(id)fp8;

@end

@interface CALMainController : NSResponder
{
    NSWindow *window;
    BMBeveledButton *backwardButton;
    BMBeveledButton *forwardButton;
    BMBeveledButton *dayButton;
    BMBeveledButton *weekButton;
    BMBeveledButton *monthButton;
    BMiTunesButton *inspectorButton;
    BMTabControl *tabControl;
    BMiTunesButton *_miniMonthButton;
    BMiTunesButton *_noBoButton;
    NSSearchField *_searchField;
    NSTableView *calendarTableView;
    CALMainCalendarView *mainCalendarView;
    NSMatrix *viewMatrix;
    NSButtonCell *listingViewButton;
    CALPaned *rightPaneSearchPaned;
    CALPaned *_tasksPaned;
    CALPaned *leftPaneSplitView;
    CALSwapView *_bottomSwapView;
    CALMiniMonthlyView *_miniMonthView;
    NSView *_noBoView;
    id searchResultContactView;
    CALSearchView *searchView;
    NSButton *_openCloseSearchListButton;
    NSSlider *timeScaleSlider;
    NSMatrix *_viewsMatrix;
    NSMenuItem *_tasksSortCriterionMenu;
    NSMenuItem *selectedThemeMenuItem;
    NSButton *tasksSwitchButton;
    CALPaned *_mainPaned;
    NSPopUpButton *_timeZonePopUpButton;
    CALNewInspector *_newInspector;
    NSString *_currentViewName;
    NSMutableDictionary *_mainCalendarViews;
    NSMutableDictionary *_tagToCalendarViewNameTable;
    CALSelectionManager *_selectionManager;
    CALHeaderedView *_taskHeaderedView;
    CALTaskManager *_taskManager;
    NSMenuItem *_showHideTasksMenuItem;
    BMiTunesButton *_peopleButton;
    NSMenuItem *_peoplePickerMenuItem;
    CALLayerManager *_layerManager;
    NSMenuItem *_goToCatalogMenuItem;
    NSMenuItem *_canvasLayerToggleMenuItem;
    NSMenuItem *_canvasFlashToggleMenuItem;
    NSMenuItem *_canvasLayersLogMenuItem;
    NSMenuItem *_canvasUsesCGMenuItem;
    NSMenuItem *_canvasUsesOpenGLMenuItem;
    NSMenuItem *_canvasUsesCGGLMenuItem;
    BOOL _useMetalInspectorWindow;
    NSMenuItem *_todoViewToggleMenuItem;
    NSString *lastRequestFile;
    NSDate *lastRequestDate;
    NSString *lastReplyFile;
    NSDate *lastReplyDate;
    NSString *_lastExportPath;
    NSString *_lastImportPath;
    NSWindow *_iSyncStartAlert;
    NSProgressIndicator *_iSyncStartAlertProgressIndicator;
    BOOL _showAlldayEvents;
    BOOL _isInModalSheet;
    BOOL _hasToDisplaySyncAlert;
    BOOL _isInUndoOperation;
    BOOL _quitEnabled;
    BOOL _sheetNotificationBlocked;
}

+ (id)defaultMainController;
- (id)init;
- (void)dealloc;
- (void)awakeFromNib;
- (id)view:(id)fp8 stringForToolTip:(int)fp12 point:(struct _NSPoint)fp16 userData:(void *)fp24;
- (void)iSyncStartAlert;
- (void)iSyncStartAlertEnd:(id)fp8;
- (void)applicationDidBecomeActive:(id)fp8;
- (void)initMainPaned;
- (void)initRightPaneSearchPaned;
- (void)checkDefaultLauncher;
- (void)checkTime;
- (unsigned int)draggingEntered:(id)fp8;
- (BOOL)performDragOperation:(id)fp8;
- (void)registerMainCalendarViewController:(id)fp8 withName:(id)fp12;
- (void)loadMainCalendarViewControllerWithName:(id)fp8 withTag:(id)fp12;
- (id)window;
- (void)beSureWindowIsVisible;
- (void)beginSheetModal:(id)fp8;
- (void)beginSheetModal:(id)fp8 withQuit:(BOOL)fp12 withUserNotification:(BOOL)fp16;
- (void)stopSheetModal:(id)fp8;
- (void)sheetDidEnd:(id)fp8 returnCode:(int)fp12 contextInfo:(void *)fp16;
- (BOOL)userNotificationBlocked;
- (BOOL)isInModalSheet;
- (BOOL)isQuitEnabled;
- (id)backwardButton;
- (id)forwardButton;
- (id)listingViewButton;
- (id)timeScaleSlider;
- (id)searchView;
- (id)rightPaneSearchPaned;
- (id)leftPaneSplitView;
- (id)tasksPaned;
- (id)mainCalendarView;
- (id)mainCalendarViews;
- (id)layerManager;
- (id)taskManager;
- (id)selectionManager;
- (BOOL)isSearchActive;
- (void)setIsSearchActive:(BOOL)fp8;
- (void)showHideSearchResults:(id)fp8;
- (BOOL)searchResultsIsOpened;
- (void)find:(id)fp8;
- (void)calPanedDidClose:(id)fp8;
- (void)calPanedDidOpen:(id)fp8;
- (void)backup:(id)fp8;
- (void)restore:(id)fp8;
- (void)datetimeFormatChangedNotificationHandler:(id)fp8;
- (void)screenResolutionChangedNotificationHandler:(id)fp8;
- (id)calendarViewController;
- (id)tagToCalendarViewNameTable;
- (id)tagToViewName:(id)fp8;
- (id)findNewStartDateForTargetNDays:(int)fp8;
- (void)setCalendarViewTo:(id)fp8 withNDays:(int)fp12;
- (void)notYetImplemented:(id)fp8;
- (void)readOnlyCalendarAlert;
- (BOOL)checkEntityCreationIsValid;
- (void)newEntityRequest:(id)fp8;
- (void)newEntityCommand:(id)fp8;
- (void)initTasksPaned;
- (void)showHideTasksPane:(id)fp8;
- (BOOL)tasksPaneShown;
- (void)setTasksShown:(BOOL)fp8;
- (void)newTodoCommand:(id)fp8;
- (void)editTodoCommand:(id)fp8;
- (void)focusOnMainView;
- (void)postEventCreationStuff:(id)fp8 withEdition:(BOOL)fp12;
- (void)editEntityRequest:(id)fp8;
- (void)timeRangeChanged:(id)fp8;
- (void)goToDate:(id)fp8;
- (void)switchToOneDayView;
- (void)switchToWeekView;
- (void)timeScaleChanged:(id)fp8;
- (void)goToCurrentDay:(id)fp8;
- (void)goToDay:(id)fp8;
- (void)switchToDayView:(id)fp8;
- (void)switchToWeekView:(id)fp8;
- (void)switchToMonthView:(id)fp8;
- (void)moveForward:(id)fp8;
- (void)moveBackward:(id)fp8;
- (void)moveToEndOfLine:(id)fp8;
- (void)moveToBeginningOfLine:(id)fp8;
- (void)showUserFeedbackPage:(id)fp8;
- (void)shopForProducts:(id)fp8;
- (void)registerICal:(id)fp8;
- (void)goToCatalog:(id)fp8;
- (void)print:(id)fp8;
- (float)admissibleSliderPositionForPosition:(float)fp8;
- (void)userResizedMiniMonth:(id)fp8;
- (void)showHideMiniMonthPane:(id)fp8;
- (BOOL)miniMonthShown;
- (void)setMiniMonthShown:(BOOL)fp8;
- (void)initMiniMonthNoBoSwapViewPane;
- (void)showHideNoBoCommand:(id)fp8;
- (BOOL)noBoShown;
- (void)setNoBoShown:(BOOL)fp8;
- (void)entriesInNoBoHasChanged:(id)fp8;
- (id)newInspector;
- (void)showNewPreferences:(id)fp8;
- (void)openInspector:(id)fp8;
- (void)closeInspector:(id)fp8;
- (BOOL)isInspectorOpen;
- (void)inspectorButtonClicked:(id)fp8;
- (void)displayInspectorInWindowOrNot:(id)fp8;
- (void)displayInspectorInWindowStateHasChanged:(id)fp8;
- (void)showKeyboardShortcuts:(id)fp8;
- (BOOL)showAlldayEvents;
- (void)showAlldayEventsCommand:(id)fp8;
- (void)inspectorDidClose;
- (BOOL)hasFutureAlarms;
- (int)applicationShouldTerminate:(id)fp8;
- (void)performClose:(id)fp8;
- (BOOL)windowShouldClose:(id)fp8;
- (void)bringAllToFront:(id)fp8;
- (void)showCalendarsWindow:(id)fp8;
- (BOOL)applicationShouldHandleReopen:(id)fp8 hasVisibleWindows:(BOOL)fp12;
- (void)fileSystemChanged:(id)fp8;
- (void)peoplePickerWindowWillClose:(id)fp8;
- (void)showPeoplePicker;
- (void)hidePeoplePicker;
- (void)showHidePeoplePicker:(id)fp8;
- (void)openAddressBook:(id)fp8;
- (BOOL)isAddressBookOK;
- (void)indicateInvitationIsNotValid;
- (BOOL)checkInvitatingIsValid;
- (void)registerProperlyHelpBook;
- (void)initTimeZonePopUp;
- (id)timeZonePopUpButton;
- (void)setTimeZonePopupShowed:(BOOL)fp8;
- (void)timeZoneEnabledPrefChanged:(id)fp8;

@end

@interface CALSoundAlarm : CALAlarm
{
}

+ (id)alarmWithTrigger:(id)fp8;
- (id)initWithTrigger:(id)fp8;
- (Class)correspondingOccurrenceClass;
- (id)URL;
- (id)setURL:(id)fp8;
- (void)dealloc;

@end

@interface CALDisplayAlarm : CALAlarm
{
}

+ (id)alarmWithTrigger:(id)fp8 withDesc:(id)fp12;
- (id)initWithTrigger:(id)fp8;
- (id)initWithTrigger:(id)fp8 withDesc:(id)fp12;
- (Class)correspondingOccurrenceClass;
- (id)desc;
- (id)setDesc:(id)fp8;

@end


@interface CALTodo : CALEntity
{   
}   

+ (id)todo;
- (Class)correspondingOccurrenceClass;
- (void)actualCommitWithUndo:(BOOL)fp8;
- (void)forceDatesToGMT;
- (id)completionDate;
- (BOOL)isCompleted;
- (void)setStatus:(int)fp8;
- (void)setCompletionDate:(id)fp8;
- (id)dueDate;
- (void)setDueDate:(id)fp8;
- (id)duration;
- (void)setDuration:(id)fp8;
- (int)priority;
- (void)setPriority:(int)fp8;
- (id)masterTodoUID;
- (void)setMasterTodoUID:(id)fp8;
- (id)location;
- (void)setLocation:(id)fp8;
- (void)cleanUp;
- (id)checkValidity;
- (id)upperBoundDate;
- (id)expandOnTimeRange:(id)fp8;

@end

@interface CALView: NSObject
@end

@interface CALDaemonMainController: NSObject
@end

@interface CALDaemonAlarmController : NSObject
{
    CALView *_calView;
    CALDaemonMainController *mainController;
    NSTimer *_updateTimer;
}

- (void)awakeFromNib;
- (void)maybeQuit:(id)fp8;
- (void)triggerImmediatelyAlarmOccurrences:(id)fp8;
- (void)alarmsTriggered:(id)fp8;
- (void)displayAlarm:(id)fp8;
- (void)planWakeUpAndMaybeQuit;
- (void)alarmWindowClosed:(id)fp8;

@end

