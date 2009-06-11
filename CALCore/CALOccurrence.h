@interface CALOccurrence : NSObject
{
    CALDate *_initialStartDate; // 4 = 0x4
    CALDate *_startDate;        // 8 = 0x8
    CALOccurrableEntity *_realEntity;   // 12 = 0xc
    NSMutableDictionary *_clientData;   // 16 = 0x10
    NSString *_occurrenceID;    // 20 = 0x14
    BOOL _discard;      // 24 = 0x18
}

- (id)description;
- (id)initWithOccurrableEntity:(id)fp8 withStartDate:(id)fp12;
- (void)discard;
- (BOOL)isDiscarded;
- (void)reset;
- (id)startDate;
- (id)clientData;
- (id)initialStartDate;
- (void)setStartDate:(id)fp8;
- (void)setStartDateAndTimeZone:(id)fp8;
- (id)entity;
- (BOOL)isMainOccurrence;
- (BOOL)isEqual:(id)fp8;
- (BOOL)isEqualToOccurrence:(id)fp8;
- (id)occurrenceID;
- (int)compare:(id)fp8;
- (id)makeEntityFromOccurrence;
- (void)dealloc;

@end

