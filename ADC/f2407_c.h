/* Core registers */
#define IMR          (volatile unsigned int *)0x0004   /* Interrupt mask reg */
#define GREG         (volatile unsigned int *)0x0005   /* Global memory allocation reg */
#define IFR          (volatile unsigned int *)0x0006   /* Interrupt flag reg */

/* System configuration and interrupt registers */
#define PIRQR0       (volatile unsigned int *)0x7010   /* Peripheral interrupt request reg 0 */
#define PIRQR1       (volatile unsigned int *)0x7011   /* Peripheral interrupt request reg 1 */
#define PIRQR2       (volatile unsigned int *)0x7012   /* Peripheral interrupt request reg 2 */ 
#define PIACKR0      (volatile unsigned int *)0x7014   /* Peripheral interrupt acknowledge reg 0 */
#define PIACKR1      (volatile unsigned int *)0x7015   /* Peripheral interrupt acknowledge reg 1 */
#define PIACKR2      (volatile unsigned int *)0x7016   /* Peripheral interrupt acknowledge reg 2 */
#define SCSR1        (volatile unsigned int *)0x7018   /* System control & status reg 1 */
#define SCSR2        (volatile unsigned int *)0x7019   /* System control & status reg 2 */
#define DINR         (volatile unsigned int *)0x701C   /* Device identification reg */
#define PIVR         (volatile unsigned int *)0x701E   /* Peripheral interrupt vector reg */

/* Watchdog timer (WD) registers */
#define WDCNTR       (volatile unsigned int *)0x7023   /* WD counter reg */
#define WDKEY        (volatile unsigned int *)0x7025   /* WD reset key reg */
#define WDCR         (volatile unsigned int *)0x7029   /* WD timer control reg */

/* Serial Peripheral Interface (SPI) registers */
#define SPICCR       (volatile unsigned int *)0x7040   /* SPI configuration control reg */
#define SPICTL       (volatile unsigned int *)0x7041   /* SPI operation control reg */
#define SPISTS       (volatile unsigned int *)0x7042   /* SPI status reg */
#define SPIBRR       (volatile unsigned int *)0x7044   /* SPI baud rate reg */
#define SPIRXEMU     (volatile unsigned int *)0x7046   /* SPI emulation buffer reg */
#define SPIRXBUF     (volatile unsigned int *)0x7047   /* SPI serial receive buffer reg */
#define SPITXBUF     (volatile unsigned int *)0x7048   /* SPI serial transmit buffer reg */
#define SPIDAT       (volatile unsigned int *)0x7049   /* SPI serial data reg */
#define SPIPRI       (volatile unsigned int *)0x704F   /* SPI priority control reg */

/* SCI registers */
#define SCICCR       (volatile unsigned int *)0x7050   /* SCI communication control reg */
#define SCICTL1      (volatile unsigned int *)0x7051   /* SCI control reg 1 */
#define SCIHBAUD     (volatile unsigned int *)0x7052   /* SCI baud-select reg, high bits */
#define SCILBAUD     (volatile unsigned int *)0x7053   /* SCI baud-select reg, low bits */
#define SCICTL2      (volatile unsigned int *)0x7054   /* SCI control reg 2 */
#define SCIRXST      (volatile unsigned int *)0x7055   /* SCI receiver status reg */
#define SCIRXEMU     (volatile unsigned int *)0x7056   /* SCI emulation data buffer reg */
#define SCIRXBUF     (volatile unsigned int *)0x7057   /* SCI receiver data buffer reg */
#define SCITXBUF     (volatile unsigned int *)0x7059   /* SCI transmit data buffer reg */
#define SCIPRI       (volatile unsigned int *)0x705F   /* SCI priority control reg */

/* External interrupt configuration registers */
#define XINT1CR      (volatile unsigned int *)0x7070   /* Ext interrupt 1 config reg */
#define XINT2CR      (volatile unsigned int *)0x7071   /* Ext interrupt 2 config reg */

/* Digital I/O registers */
#define MCRA         (volatile unsigned int *)0x7090   /* I/O mux control reg A */
#define MCRB         (volatile unsigned int *)0x7092   /* I/O mux control reg B */
#define MCRC         (volatile unsigned int *)0x7094   /* I/O mux control reg C */
#define PADATDIR     (volatile unsigned int *)0x7098   /* I/O port A data & dir reg */
#define PBDATDIR     (volatile unsigned int *)0x709A   /* I/O port B data & dir reg */
#define PCDATDIR     (volatile unsigned int *)0x709C   /* I/O port C data & dir reg */
#define PDDATDIR     (volatile unsigned int *)0x709E   /* I/O port D data & dir reg */
#define PEDATDIR     (volatile unsigned int *)0x7095   /* I/O port E data & dir reg */
#define PFDATDIR     (volatile unsigned int *)0x7096   /* I/O port F data & dir reg */

/* Analog-to-Digital Converter (ADC) registers */
#define ADCTRL1      (volatile unsigned int *)0x70A0   /* ADC control reg 1 */
#define ADCTRL2      (volatile unsigned int *)0x70A1   /* ADC control reg 2 */
#define MAX_CONV     (volatile unsigned int *)0x70A2   /* Maximum conversion channels reg */
#define CHSELSEQ1    (volatile unsigned int *)0x70A3   /* Channel select sequencing control reg 1 */
#define CHSELSEQ2    (volatile unsigned int *)0x70A4   /* Channel select sequencing control reg 2 */
#define CHSELSEQ3    (volatile unsigned int *)0x70A5   /* Channel select sequencing control reg 3 */
#define CHSELSEQ4    (volatile unsigned int *)0x70A6   /* Channel select sequencing control reg 4 */
#define AUTO_SEQ_SR  (volatile unsigned int *)0x70A7   /* Autosequence status reg */
#define RESULT0      (volatile unsigned int *)0x70A8   /* Conversion result buffer reg 0 */
#define RESULT1      (volatile unsigned int *)0x70A9   /* Conversion result buffer reg 1 */
#define RESULT2      (volatile unsigned int *)0x70AA   /* Conversion result buffer reg 2 */
#define RESULT3      (volatile unsigned int *)0x70AB   /* Conversion result buffer reg 3 */
#define RESULT4      (volatile unsigned int *)0x70AC   /* Conversion result buffer reg 4 */
#define RESULT5      (volatile unsigned int *)0x70AD   /* Conversion result buffer reg 5 */
#define RESULT6      (volatile unsigned int *)0x70AE   /* Conversion result buffer reg 6 */
#define RESULT7      (volatile unsigned int *)0x70AF   /* Conversion result buffer reg 7 */
#define RESULT8      (volatile unsigned int *)0x70B0   /* Conversion result buffer reg 8 */
#define RESULT9      (volatile unsigned int *)0x70B1   /* Conversion result buffer reg 9 */
#define RESULT10     (volatile unsigned int *)0x70B2   /* Conversion result buffer reg 10 */
#define RESULT11     (volatile unsigned int *)0x70B3   /* Conversion result buffer reg 11 */
#define RESULT12     (volatile unsigned int *)0x70B4   /* Conversion result buffer reg 12 */
#define RESULT13     (volatile unsigned int *)0x70B5   /* Conversion result buffer reg 13 */
#define RESULT14     (volatile unsigned int *)0x70B6   /* Conversion result buffer reg 14 */
#define RESULT15     (volatile unsigned int *)0x70B7   /* Conversion result buffer reg 15 */
#define CALIBRATION  (volatile unsigned int *)0x70B8   /* Calibration result reg */

/* Controller Area Network (CAN) registers */
#define MDER         (volatile unsigned int *)0x7100   /* CAN mailbox direction/enable reg */
#define TCR          (volatile unsigned int *)0x7101   /* CAN transmission control reg */
#define RCR          (volatile unsigned int *)0x7102   /* CAN receive control reg */
#define MCR          (volatile unsigned int *)0x7103   /* CAN master control reg */
#define BCR2         (volatile unsigned int *)0x7104   /* CAN bit config reg 2 */
#define BCR1         (volatile unsigned int *)0x7105   /* CAN bit config reg 1 */
#define ESR          (volatile unsigned int *)0x7106   /* CAN error status reg */
#define GSR          (volatile unsigned int *)0x7107   /* CAN global status reg */
#define CEC          (volatile unsigned int *)0x7108   /* CAN trans and rcv err counters */
#define CAN_IFR      (volatile unsigned int *)0x7109   /* CAN interrupt flag reg */
#define CAN_IMR      (volatile unsigned int *)0x710A   /* CAN interrupt mask reg */
#define LAM0_H       (volatile unsigned int *)0x710B   /* CAN local acceptance mask MBX0/1 */
#define LAM0_L       (volatile unsigned int *)0x710C   /* CAN local acceptance mask MBX0/1 */
#define LAM1_H       (volatile unsigned int *)0x710D   /* CAN local acceptance mask MBX2/3 */
#define LAM1_L       (volatile unsigned int *)0x710E   /* CAN local acceptance mask MBX2/3 */

#define MSGID0L      (volatile unsigned int *)0x7200   /* CAN message ID for mailbox 0 (lower 16 bits) */
#define MSGID0H      (volatile unsigned int *)0x7201   /* CAN message ID for mailbox 0 (upper 16 bits) */
#define MSGCTRL0     (volatile unsigned int *)0x7202   /* CAN RTR and DLC for mailbox 0 */
#define MBX0A        (volatile unsigned int *)0x7204   /* CAN 2 of 8 bytes of mailbox 0 */
#define MBX0B        (volatile unsigned int *)0x7205   /* CAN 2 of 8 bytes of mailbox 0 */
#define MBX0C        (volatile unsigned int *)0x7206   /* CAN 2 of 8 bytes of mailbox 0 */
#define MBX0D        (volatile unsigned int *)0x7207   /* CAN 2 of 8 bytes of mailbox 0 */

#define MSGID1L      (volatile unsigned int *)0x7208   /* CAN message ID for mailbox 1 (lower 16 bits) */
#define MSGID1H      (volatile unsigned int *)0x7209   /* CAN message ID for mailbox 1 (upper 16 bits) */
#define MSGCTRL1     (volatile unsigned int *)0x720A   /* CAN RTR and DLC for mailbox 1 */
#define MBX1A        (volatile unsigned int *)0x720C   /* CAN 2 of 8 bytes of mailbox 1 */
#define MBX1B        (volatile unsigned int *)0x720D   /* CAN 2 of 8 bytes of mailbox 1 */
#define MBX1C        (volatile unsigned int *)0x720E   /* CAN 2 of 8 bytes of mailbox 1 */
#define MBX1D        (volatile unsigned int *)0x720F   /* CAN 2 of 8 bytes of mailbox 1 */

#define MSGID2L      (volatile unsigned int *)0x7210   /* CAN message ID for mailbox 2 (lower 16 bits) */
#define MSGID2H      (volatile unsigned int *)0x7211   /* CAN message ID for mailbox 2 (upper 16 bits) */
#define MSGCTRL2     (volatile unsigned int *)0x7212   /* CAN RTR and DLC for mailbox 2 */
#define MBX2A        (volatile unsigned int *)0x7214   /* CAN 2 of 8 bytes of mailbox 2 */
#define MBX2B        (volatile unsigned int *)0x7215   /* CAN 2 of 8 bytes of mailbox 2 */
#define MBX2C        (volatile unsigned int *)0x7216   /* CAN 2 of 8 bytes of mailbox 2 */
#define MBX2D        (volatile unsigned int *)0x7217   /* CAN 2 of 8 bytes of mailbox 2 */

#define MSGID3L      (volatile unsigned int *)0x7218   /* CAN message ID for mailbox 3 (lower 16 bits) */
#define MSGID3H      (volatile unsigned int *)0x7219   /* CAN message ID for mailbox 3 (upper 16 bits) */
#define MSGCTRL3     (volatile unsigned int *)0x721A   /* CAN RTR and DLC for mailbox 3 */
#define MBX3A        (volatile unsigned int *)0x721C   /* CAN 2 of 8 bytes of mailbox 3 */
#define MBX3B        (volatile unsigned int *)0x721D   /* CAN 2 of 8 bytes of mailbox 3 */
#define MBX3C        (volatile unsigned int *)0x721E   /* CAN 2 of 8 bytes of mailbox 3 */
#define MBX3D        (volatile unsigned int *)0x721F   /* CAN 2 of 8 bytes of mailbox 3 */

#define MSGID4L      (volatile unsigned int *)0x7220   /* CAN message ID for mailbox 4 (lower 16 bits) */
#define MSGID4H      (volatile unsigned int *)0x7221   /* CAN message ID for mailbox 4 (upper 16 bits) */
#define MSGCTRL4     (volatile unsigned int *)0x7222   /* CAN RTR and DLC for mailbox 4 */
#define MBX4A        (volatile unsigned int *)0x7224   /* CAN 2 of 8 bytes of mailbox 4 */
#define MBX4B        (volatile unsigned int *)0x7225   /* CAN 2 of 8 bytes of mailbox 4 */
#define MBX4C        (volatile unsigned int *)0x7226   /* CAN 2 of 8 bytes of mailbox 4 */
#define MBX4D        (volatile unsigned int *)0x7227   /* CAN 2 of 8 bytes of mailbox 4 */

#define MSGID5L      (volatile unsigned int *)0x7228   /* CAN message ID for mailbox 5 (lower 16 bits) */
#define MSGID5H      (volatile unsigned int *)0x7229   /* CAN message ID for mailbox 5 (upper 16 bits) */
#define MSGCTRL5     (volatile unsigned int *)0x722A   /* CAN RTR and DLC for mailbox 5 */
#define MBX5A        (volatile unsigned int *)0x722C   /* CAN 2 of 8 bytes of mailbox 5 */
#define MBX5B        (volatile unsigned int *)0x722D   /* CAN 2 of 8 bytes of mailbox 5 */
#define MBX5C        (volatile unsigned int *)0x722E   /* CAN 2 of 8 bytes of mailbox 5 */
#define MBX5D        (volatile unsigned int *)0x722F   /* CAN 2 of 8 bytes of mailbox 5 */

/* Event Manager A (EVA) registers */
#define GPTCONA      (volatile unsigned int *)0x7400   /* GP timer control reg A */
#define T1CNT        (volatile unsigned int *)0x7401   /* GP timer 1 counter reg */
#define T1CMPR       (volatile unsigned int *)0x7402   /* GP timer 1 compare reg */
#define T1PR         (volatile unsigned int *)0x7403   /* GP timer 1 period reg  */
#define T1CON        (volatile unsigned int *)0x7404   /* GP timer 1 control reg */
#define T2CNT        (volatile unsigned int *)0x7405   /* GP timer 2 counter reg */
#define T2CMPR       (volatile unsigned int *)0x7406   /* GP timer 2 compare reg */ 
#define T2PR         (volatile unsigned int *)0x7407   /* GP timer 2 period reg */
#define T2CON        (volatile unsigned int *)0x7408   /* GP timer 2 control reg */
#define COMCONA      (volatile unsigned int *)0x7411   /* Compare control reg A */
#define ACTRA        (volatile unsigned int *)0x7413   /* Compare action control reg A */
#define DBTCONA      (volatile unsigned int *)0x7415   /* Dead-band timer control reg A */
#define CMPR1        (volatile unsigned int *)0x7417   /* compare reg 1 */
#define CMPR2        (volatile unsigned int *)0x7418   /* compare reg 2 */ 
#define CMPR3        (volatile unsigned int *)0x7419   /* compare reg 3 */ 
#define CAPCONA      (volatile unsigned int *)0x7420   /* Capture control reg A */
#define CAPFIFOA     (volatile unsigned int *)0x7422   /* Capture FIFO status reg A */
#define CAP1FIFO     (volatile unsigned int *)0x7423   /* Capture Channel 1 FIFO top */
#define CAP2FIFO     (volatile unsigned int *)0x7424   /* Capture Channel 2 FIFO top */ 
#define CAP3FIFO     (volatile unsigned int *)0x7425   /* Capture Channel 3 FIFO top */ 
#define CAP1FBOT     (volatile unsigned int *)0x7427   /* Bottom reg of capture FIFO stack 1 */
#define CAP2FBOT     (volatile unsigned int *)0x7428   /* Bottom reg of capture FIFO stack 2 */ 
#define CAP3FBOT     (volatile unsigned int *)0x7429   /* Bottom reg of capture FIFO stack 3 */ 
#define EVAIMRA      (volatile unsigned int *)0x742C   /* EVA interrupt mask reg A */
#define EVAIMRB      (volatile unsigned int *)0x742D   /* EVA interrupt mask reg B */
#define EVAIMRC      (volatile unsigned int *)0x742E   /* EVA interrupt mask reg C */
#define EVAIFRA      (volatile unsigned int *)0x742F   /* EVA interrupt flag reg A */
#define EVAIFRB      (volatile unsigned int *)0x7430   /* EVA interrupt flag reg B */
#define EVAIFRC      (volatile unsigned int *)0x7431   /* EVA interrupt flag reg C */

/* Event Manager B (EVB) registers */
#define GPTCONB      (volatile unsigned int *)0x7500   /* GP timer control reg B */
#define T3CNT        (volatile unsigned int *)0x7501   /* GP timer 3 counter reg */
#define T3CMPR       (volatile unsigned int *)0x7502   /* GP timer 3 compare reg */
#define T3PR         (volatile unsigned int *)0x7503   /* GP timer 3 period reg */
#define T3CON        (volatile unsigned int *)0x7504   /* GP timer 3 control reg */
#define T4CNT        (volatile unsigned int *)0x7505   /* GP timer 4 counter reg */
#define T4CMPR       (volatile unsigned int *)0x7506   /* GP timer 4 compare reg */
#define T4PR         (volatile unsigned int *)0x7507   /* GP timer 4 period reg */
#define T4CON        (volatile unsigned int *)0x7508   /* GP timer 4 control reg */
#define COMCONB      (volatile unsigned int *)0x7511   /* Compare control register B */
#define ACTRB        (volatile unsigned int *)0x7513   /* Compare action control register B */
#define DBTCONB      (volatile unsigned int *)0x7515   /* Dead-band timer control reg B */
#define CMPR4        (volatile unsigned int *)0x7517   /* Compare reg 4 */
#define CMPR5        (volatile unsigned int *)0x7518   /* Compare reg 5 */
#define CMPR6        (volatile unsigned int *)0x7519   /* Compare reg 6 */
#define CAPCONB      (volatile unsigned int *)0x7520   /* Capture control reg B */
#define CAPFIFOB     (volatile unsigned int *)0x7522   /* Capture FIFO status reg B */
#define CAP4FIFO     (volatile unsigned int *)0x7523   /* Capture channel 4 FIFO top */
#define CAP5FIFO     (volatile unsigned int *)0x7524   /* Capture channel 5 FIFO top */
#define CAP6FIFO     (volatile unsigned int *)0x7525   /* Capture channel 6 FIFO top */
#define CAP4FBOT     (volatile unsigned int *)0x7527   /* Bottom reg of capture FIFO stack 4 */
#define CAP5FBOT     (volatile unsigned int *)0x7528   /* Bottom reg of capture FIFO stack 5 */
#define CAP6FBOT     (volatile unsigned int *)0x7529   /* Bottom reg of capture FIFO stack 6 */
#define EVBIMRA      (volatile unsigned int *)0x752C   /* EVB interrupt mask reg A */
#define EVBIMRB      (volatile unsigned int *)0x752D   /* EVB interrupt mask reg B */
#define EVBIMRC      (volatile unsigned int *)0x752E   /* EVB interrupt mask reg C */
#define EVBIFRA      (volatile unsigned int *)0x752F   /* EVB interrupt flag reg A */
#define EVBIFRB      (volatile unsigned int *)0x7530   /* EVB interrupt flag reg B */
#define EVBIFRC      (volatile unsigned int *)0x7531   /* EVB interrupt flag reg C */

/* I/O space mapped registers */
#define FCMR portFF0F                                  /* Flash control mode register */
ioport unsigned int portFF0F;                          /* C2xx compiler specific keyword */
#define WSGR portFFFF                                  /* Wait-state generator reg */
ioport unsigned int portFFFF;                          /* C2xx compiler specific keyword */


