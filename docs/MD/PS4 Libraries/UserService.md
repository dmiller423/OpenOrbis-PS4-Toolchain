# UserService library
The UserService library is used for accessing information on system users as well as applying user settings like volume.

### Known Macros
The system has it's own user ID, being `0xFF`.

```c
#define ORBIS_USER_SERVICE_USER_ID_SYSTEM 0xFF
```

One can also set priority levels on users. The lowest priority is `0x2FF` where the highest is `0x100`. The sweet spot / normal is `0x2BC`.

```c
#define ORBIS_KERNEL_PRIO_FIFO_LOWEST  0x2FF
#define ORBIS_KERNEL_PRIO_FIFO_NORMAL  0x2BC
#define ORBIS_KERNEL_PRIO_FIFO_HIGHEST 0x100
```

### Known Structures

#### OrbisUserServiceInitializeParams
The service initialize parameters structure is used to initialize the user service library. The parameters only include one known parameter, being the priority.

```c
typedef struct OrbisUserServiceInitializeParams {
	uint32_t priority;
} OrbisUserServiceInitializeParams;
```

#### OrbisUserServiceLoginUserIdList
The service login user ID list structure is used as a container for a list of 4 potential user IDs currently logged in on the system.

```c
typedef struct OrbisUserServiceLoginUserIdList {
	OrbisUserServiceUserId userId[4];
} OrbisUserServiceLoginUserIdList;
```

### Known Functions

**sceUserServiceInitialize(OrbisUserServiceInitializeParams \*params)**

```c
int sceUserServiceInitialize(OrbisUserServiceInitializeParams *params)
```

Initializes the user service library with the given `params`.

**sceUserServiceGetInitialUser(\*outUserID)**

```c
int sceUserServiceGetInitialUser(int *outUserID)
```

Gets the user ID of the primary user and writes it to `outUserID`.

**sceUserServiceGetUserName(id, \*outName, outMaxSize)**

```c
int sceUserServiceGetUserName(int userID, char *outName, size_t maxSize)
```

Gets the username of `userID` and writes it to `outName` to a maximum of `maxSize` bytes.

**sceUserServiceGetLoginUserIdList(OrbisUserServiceLoginUserIdList \*)**

```c
int sceUserServiceGetLoginUserIdList(OrbisUserServiceLoginUserIdList *);
```

Returns a listing of currently logged in users.

## Reversing Credits
- Various scene developers