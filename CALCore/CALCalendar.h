@interface CALCalendar : CALAbstractEntity
{
    NSMutableDictionary *_uidstorage;   // 36 = 0x24
    NSMutableArray *_orderedstorage;    // 40 = 0x28
}

+ (id)calendarFromDictionary:(id)fp8;
+ (id)calendar;
+ (id)calendarWithEntities:(id)fp8;
+ (id)calendarWithEntity:(id)fp8;
+ (id)calendarWithCalendar:(id)fp8;
- (id)description;
- (id)init;
- (id)initWithEntitiesIncludingChildren:(id)fp8;
- (id)initWithEntities:(id)fp8 copy:(BOOL)fp12;
- (id)initFromDictionary:(id)fp8;
- (id)initWithEntities:(id)fp8;
- (id)initWithSingleEntity:(id)fp8;
- (id)initWithCalendar:(id)fp8;
- (id)copyWithZone:(struct _NSZone *)fp8;
- (void)dealloc;
- (void)markAsClean;
- (void)forceToGMT;
- (void)generateIDsWithSuffix:(id)fp8;
- (void)generateNewIDs;
- (void)fixUIDStorage;
- (id)generateDictionary;
- (void)fixEntitiesRelationship;
- (id)setupLanguageInformation;
- (id)removeLanguageInformation;
- (id)languageInformation;
- (int)method;
- (id)setMethod:(int)fp8;
- (id)relcalid;
- (id)setRelcalid:(id)fp8;
- (id)name;
- (id)setName:(id)fp8;
- (BOOL)hasDesc;
- (id)desc;
- (id)setDesc:(id)fp8;
- (id)setupRelcalid;
- (id)version;
- (id)setVersion:(id)fp8;
- (id)prodID;
- (id)setProdID:(id)fp8;
- (id)timeZoneHint;
- (id)setTimeZoneHint:(id)fp8;
- (id)calendarType;
- (void)setCalendarType:(id)fp8;
- (id)expiration;
- (void)setExpiration:(id)fp8;
- (void)setupDotMacProperties;
- (void)setupStandardProperties;
- (id)calscale;
- (id)setCalscale:(id)fp8;
- (id)timeZonesInCalendar;
- (id)timeZoneIdentifiersInCalendar;
- (id)entities;
- (id)journals;
- (id)events;
- (id)todos;
- (id)timezones;
- (void)addEntity:(id)fp8;
- (void)addEntityAtStart:(id)fp8;
- (void)addEntities:(id)fp8;
- (void)replaceEntity:(id)fp8 withEntity:(id)fp12;
- (void)removeEntities:(id)fp8;
- (void)removeEntity:(id)fp8;
- (unsigned int)countEntities;
- (void)removeEntityByPrivateID:(id)fp8;
- (id)entityForUID:(id)fp8 withRecurrenceID:(id)fp12;
- (id)entityForPrivateID:(id)fp8;
- (id)entitiesForUID:(id)fp8;
- (BOOL)containsEntity:(id)fp8 withRecurrenceID:(id)fp12;
- (BOOL)containsEntityWithPrivateID:(id)fp8;
- (id)entitiesEndingBefore:(id)fp8;
- (id)entitiesStartingBefore:(id)fp8 includingRecurringEvents:(BOOL)fp12;
- (void)setupTimeZones;

@end
