@interface CALPreferencesGeneralPaneController : NSObject
{
    NSView *generalView;
    NSView *sharingView;
    NSView *advancedView;
    id startHourPopup;
    id endHourPopup;
    id dayStartPopup;
    BOOL _validateClose;
}

- (id)init;
- (void)awakeFromNib;
- (void)_generateHoursOfDayInPopup:(id)fp8 morning:(BOOL)fp12;
- (void)_generateDayOfWeekInPopUp:(id)fp8;
- (id)imageForPaneWithIdentifiers:(id)fp8;
- (id)viewForPaneWithIdentifiers:(id)fp8;
- (id)labelForPaneWithIdentifiers:(id)fp8;
- (id)tooltipForPaneWithIdentifiers:(id)fp8;
- (id)titleForPaneWithIdentifiers:(id)fp8;
- (void)panesController:(id)fp8 willDesactivatePaneWithIdentifier:(id)fp12;
- (void)panesController:(id)fp8 didActivatePaneWithIdentifier:(id)fp12;

@end


