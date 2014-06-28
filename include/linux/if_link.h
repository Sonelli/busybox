#ifndef _LINUX_IF_LINK_H
#define _LINUX_IF_LINK_H

#include <linux/types.h>
#include <linux/netlink.h>

// parts removed

struct rtnl_link_stats64 {
	__u64	rx_packets;		/* total packets received	*/
	__u64	tx_packets;		/* total packets transmitted	*/
	__u64	rx_bytes;		/* total bytes received 	*/
	__u64	tx_bytes;		/* total bytes transmitted	*/
	__u64	rx_errors;		/* bad packets received		*/
	__u64	tx_errors;		/* packet transmit problems	*/
	__u64	rx_dropped;		/* no space in linux buffers	*/
	__u64	tx_dropped;		/* no space available in linux	*/
	__u64	multicast;		/* multicast packets received	*/
	__u64	collisions;

	/* detailed rx_errors: */
	__u64	rx_length_errors;
	__u64	rx_over_errors;		/* receiver ring buff overflow	*/
	__u64	rx_crc_errors;		/* recved pkt with crc error	*/
	__u64	rx_frame_errors;	/* recv'd frame alignment error */
	__u64	rx_fifo_errors;		/* recv'r fifo overrun		*/
	__u64	rx_missed_errors;	/* receiver missed packet	*/

	/* detailed tx_errors */
	__u64	tx_aborted_errors;
	__u64	tx_carrier_errors;
	__u64	tx_fifo_errors;
	__u64	tx_heartbeat_errors;
	__u64	tx_window_errors;

	/* for cslip etc */
	__u64	rx_compressed;
	__u64	tx_compressed;
};

// parts removed

enum
{
	IFLA_INFO_UNSPEC,
	IFLA_INFO_KIND,
	IFLA_INFO_DATA,
	IFLA_INFO_XSTATS,
	__IFLA_INFO_MAX,
};

#define IFLA_INFO_MAX	(__IFLA_INFO_MAX - 1)

/* VLAN section */

enum
{
	IFLA_VLAN_UNSPEC,
	IFLA_VLAN_ID,
	IFLA_VLAN_FLAGS,
	IFLA_VLAN_EGRESS_QOS,
	IFLA_VLAN_INGRESS_QOS,
	__IFLA_VLAN_MAX,
};

#define IFLA_VLAN_MAX	(__IFLA_VLAN_MAX - 1)

struct ifla_vlan_flags {
	__u32	flags;
	__u32	mask;
};

enum
{
	IFLA_VLAN_QOS_UNSPEC,
	IFLA_VLAN_QOS_MAPPING,
	__IFLA_VLAN_QOS_MAX
};

#define IFLA_VLAN_QOS_MAX	(__IFLA_VLAN_QOS_MAX - 1)

struct ifla_vlan_qos_mapping
{
	__u32 from;
	__u32 to;
};

/* MACVLAN section */
enum {
	IFLA_MACVLAN_UNSPEC,
	IFLA_MACVLAN_MODE,
	__IFLA_MACVLAN_MAX,
};

#define IFLA_MACVLAN_MAX (__IFLA_MACVLAN_MAX - 1)

enum macvlan_mode {
	MACVLAN_MODE_PRIVATE = 1, /* don't talk to other macvlans */
	MACVLAN_MODE_VEPA    = 2, /* talk to other ports through ext bridge */
	MACVLAN_MODE_BRIDGE  = 4, /* talk to bridge ports directly */
	MACVLAN_MODE_PASSTHRU = 8, /* take over the underlying device */
};

/* VXLAN section */
enum {
	IFLA_VXLAN_UNSPEC,
	IFLA_VXLAN_ID,
	IFLA_VXLAN_GROUP,	/* group or remote address */
	IFLA_VXLAN_LINK,
	IFLA_VXLAN_LOCAL,
	IFLA_VXLAN_TTL,
	IFLA_VXLAN_TOS,
	IFLA_VXLAN_LEARNING,
	IFLA_VXLAN_AGEING,
	IFLA_VXLAN_LIMIT,
	IFLA_VXLAN_PORT_RANGE,	/* source port */
	IFLA_VXLAN_PROXY,
	IFLA_VXLAN_RSC,
	IFLA_VXLAN_L2MISS,
	IFLA_VXLAN_L3MISS,
	IFLA_VXLAN_PORT,	/* destination port */
	__IFLA_VXLAN_MAX
};
#define IFLA_VXLAN_MAX	(__IFLA_VXLAN_MAX - 1)

struct ifla_vxlan_port_range {
	__be16	low;
	__be16	high;
};

/* SR-IOV virtual function management section */

enum {
	IFLA_VF_INFO_UNSPEC,
	IFLA_VF_INFO,
	__IFLA_VF_INFO_MAX,
};

#define IFLA_VF_INFO_MAX (__IFLA_VF_INFO_MAX - 1)

enum {
	IFLA_VF_UNSPEC,
	IFLA_VF_MAC,		/* Hardware queue specific attributes */
	IFLA_VF_VLAN,
	IFLA_VF_TX_RATE,	/* TX Bandwidth Allocation */
	__IFLA_VF_MAX,
};

#define IFLA_VF_MAX (__IFLA_VF_MAX - 1)

struct ifla_vf_mac {
	__u32 vf;
	__u8 mac[32]; /* MAX_ADDR_LEN */
};

struct ifla_vf_vlan {
	__u32 vf;
	__u32 vlan; /* 0 - 4095, 0 disables VLAN filter */
	__u32 qos;
};

struct ifla_vf_tx_rate {
	__u32 vf;
	__u32 rate; /* Max TX bandwidth in Mbps, 0 disables throttling */
};

struct ifla_vf_info {
	__u32 vf;
	__u8 mac[32];
	__u32 vlan;
	__u32 qos;
	__u32 tx_rate;
};

/* VF ports management section
 *
 *	Nested layout of set/get msg is:
 *
 *		[IFLA_NUM_VF]
 *		[IFLA_VF_PORTS]
 *			[IFLA_VF_PORT]
 *				[IFLA_PORT_*], ...
 *			[IFLA_VF_PORT]
 *				[IFLA_PORT_*], ...
 *			...
 *		[IFLA_PORT_SELF]
 *			[IFLA_PORT_*], ...
 */

enum {
	IFLA_VF_PORT_UNSPEC,
	IFLA_VF_PORT,			/* nest */
	__IFLA_VF_PORT_MAX,
};

#define IFLA_VF_PORT_MAX (__IFLA_VF_PORT_MAX - 1)

enum {
	IFLA_PORT_UNSPEC,
	IFLA_PORT_VF,			/* __u32 */
	IFLA_PORT_PROFILE,		/* string */
	IFLA_PORT_VSI_TYPE,		/* 802.1Qbg (pre-)standard VDP */
	IFLA_PORT_INSTANCE_UUID,	/* binary UUID */
	IFLA_PORT_HOST_UUID,		/* binary UUID */
	IFLA_PORT_REQUEST,		/* __u8 */
	IFLA_PORT_RESPONSE,		/* __u16, output only */
	__IFLA_PORT_MAX,
};

#define IFLA_PORT_MAX (__IFLA_PORT_MAX - 1)

#define PORT_PROFILE_MAX	40
#define PORT_UUID_MAX		16
#define PORT_SELF_VF		-1

enum {
	PORT_REQUEST_PREASSOCIATE = 0,
	PORT_REQUEST_PREASSOCIATE_RR,
	PORT_REQUEST_ASSOCIATE,
	PORT_REQUEST_DISASSOCIATE,
};

enum {
	PORT_VDP_RESPONSE_SUCCESS = 0,
	PORT_VDP_RESPONSE_INVALID_FORMAT,
	PORT_VDP_RESPONSE_INSUFFICIENT_RESOURCES,
	PORT_VDP_RESPONSE_UNUSED_VTID,
	PORT_VDP_RESPONSE_VTID_VIOLATION,
	PORT_VDP_RESPONSE_VTID_VERSION_VIOALTION,
	PORT_VDP_RESPONSE_OUT_OF_SYNC,
	/* 0x08-0xFF reserved for future VDP use */
	PORT_PROFILE_RESPONSE_SUCCESS = 0x100,
	PORT_PROFILE_RESPONSE_INPROGRESS,
	PORT_PROFILE_RESPONSE_INVALID,
	PORT_PROFILE_RESPONSE_BADSTATE,
	PORT_PROFILE_RESPONSE_INSUFFICIENT_RESOURCES,
	PORT_PROFILE_RESPONSE_ERROR,
};

struct ifla_port_vsi {
	__u8 vsi_mgr_id;
	__u8 vsi_type_id[3];
	__u8 vsi_type_version;
	__u8 pad[3];
};


/* IPoIB section */

enum {
	IFLA_IPOIB_UNSPEC,
	IFLA_IPOIB_PKEY,
	IFLA_IPOIB_MODE,
	IFLA_IPOIB_UMCAST,
	__IFLA_IPOIB_MAX
};

enum {
	IPOIB_MODE_DATAGRAM  = 0, /* using unreliable datagram QPs */
	IPOIB_MODE_CONNECTED = 1, /* using connected QPs */
};

#define IFLA_IPOIB_MAX (__IFLA_IPOIB_MAX - 1)

#endif /* _LINUX_IF_LINK_H */
