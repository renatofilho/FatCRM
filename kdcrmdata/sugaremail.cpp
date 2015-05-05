#include "sugaremail.h"

#include <QtCore/QSharedData>
#include <QtCore/QString>
#include <QDebug>

#include <KLocale>

class SugarEmail::Private : public QSharedData
{
public:
    Private()
        : mEmpty(true)
    {

    }

    Private(const Private &other)
        : QSharedData(other)
    {
        mEmpty = other.mEmpty;

        mId = other.mId;
        mName = other.mName;
        mDateEntered = other.mDateEntered;
        mDateModified = other.mDateModified;
        mModifiedUserId = other.mModifiedUserId;
        mModifiedByName = other.mModifiedByName;
        mCreatedBy = other.mCreatedBy;
        mCreatedByName = other.mCreatedByName;
        mDeleted = other.mDeleted;
        mAssignedUserId = other.mAssignedUserId;
        mAssignedUserName = other.mAssignedUserName;

        mDateSent = other.mDateSent;
        mMessageId = other.mMessageId;
        mParentType = other.mParentType;
        mParentId = other.mParentId;
        mFromAddrName = other.mFromAddrName;
        mToAddrNAmes = other.mToAddrNAmes;
        mCcAddrNames = other.mCcAddrNames;
    }

    bool mEmpty;


    QString mId;
    QString mName;
    QString mDateEntered;
    QString mDateModified;
    QString mModifiedUserId;
    QString mModifiedByName;
    QString mCreatedBy;
    QString mCreatedByName;
    QString mDeleted;
    QString mAssignedUserId;
    QString mAssignedUserName;

    QString mDateSent;
    QString mMessageId;
    QString mParentType;
    QString mParentId;
    QString mFromAddrName;
    QString mToAddrNAmes;
    QString mCcAddrNames;

};

SugarEmail::SugarEmail()
    : d(new Private)
{
}

SugarEmail::SugarEmail(const SugarEmail &other)
    : d(other.d)
{
}

SugarEmail::~SugarEmail()
{
}

SugarEmail &SugarEmail::operator=(const SugarEmail &other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

bool SugarEmail::operator==(const SugarEmail &other) const
{
    if (d->mId != other.d->mId) {
        return false;
    }
    if (d->mName != other.d->mName) {
        return false;
    }
    if (d->mDateEntered != other.d->mDateEntered) {
        return false;
    }
    if (d->mDateModified != other.d->mDateModified) {
        return false;
    }
    if (d->mModifiedUserId != other.d->mModifiedUserId) {
        return false;
    }
    if (d->mModifiedByName != other.d->mModifiedByName) {
        return false;
    }
    if (d->mCreatedBy != other.d->mCreatedBy) {
        return false;
    }
    if (d->mCreatedByName != other.d->mCreatedByName) {
        return false;
    }
    if (d->mDeleted != other.d->mDeleted) {
        return false;
    }
    if (d->mAssignedUserId != other.d->mAssignedUserId) {
        return false;
    }
    if (d->mAssignedUserName != other.d->mAssignedUserName) {
        return false;
    }
    if (d->mDateSent != other.d->mDateSent) {
        return false;
    }
    if (d->mMessageId != other.d->mMessageId) {
        return false;
    }
    if (d->mParentType != other.d->mParentType) {
        return false;
    }
    if (d->mParentId != other.d->mParentId) {
        return false;
    }
    if (d->mFromAddrName != other.d->mFromAddrName) {
        return false;
    }
    if (d->mToAddrNAmes != other.d->mToAddrNAmes) {
        return false;
    }
    if (d->mCcAddrNames != other.d->mCcAddrNames) {
        return false;
    }
    return true;
}

bool SugarEmail::operator!=(const SugarEmail &a) const
{
    return !(a == *this);
}

bool SugarEmail::isEmpty() const
{
    return d->mEmpty;
}

void SugarEmail::clear()
{
    *this = SugarEmail();
}

void SugarEmail::setId(const QString &id)
{
    d->mEmpty = false;
    d->mId = id;
}

QString SugarEmail::id() const
{
    return d->mId;
}

void SugarEmail::setName(const QString &name)
{
    d->mEmpty = false;
    d->mName = name;
}

QString SugarEmail::name() const
{
    return d->mName;
}

void SugarEmail::setDateEntered(const QString &value)
{
    d->mEmpty = false;
    d->mDateEntered = value;
}

QString SugarEmail::dateEntered() const
{
    return d->mDateEntered;
}

void SugarEmail::setDateModified(const QString &value)
{
    d->mEmpty = false;
    d->mDateModified = value;
}

QString SugarEmail::dateModified() const
{
    return d->mDateModified;
}

void SugarEmail::setModifiedUserId(const QString &value)
{
    d->mEmpty = false;
    d->mModifiedUserId = value;
}

QString SugarEmail::modifiedUserId() const
{
    return d->mModifiedUserId;
}

void SugarEmail::setModifiedByName(const QString &value)
{
    d->mEmpty = false;
    d->mModifiedByName = value;
}

QString SugarEmail::modifiedByName() const
{
    return d->mModifiedByName;
}

void SugarEmail::setCreatedBy(const QString &value)
{
    d->mEmpty = false;
    d->mCreatedBy = value;
}

QString SugarEmail::createdBy() const
{
    return d->mCreatedBy;
}

void SugarEmail::setCreatedByName(const QString &value)
{
    d->mEmpty = false;
    d->mCreatedByName = value;
}

QString SugarEmail::createdByName() const
{
    return d->mCreatedByName;
}

void SugarEmail::setDeleted(const QString &value)
{
    d->mEmpty = false;
    d->mDeleted = value;
}

QString SugarEmail::deleted() const
{
    return d->mDeleted;
}

void SugarEmail::setAssignedUserId(const QString &value)
{
    d->mEmpty = false;
    d->mAssignedUserId = value;
}

QString SugarEmail::assignedUserId() const
{
    return d->mAssignedUserId;
}

void SugarEmail::setAssignedUserName(const QString &value)
{
    d->mEmpty = false;
    d->mAssignedUserName = value;
}

QString SugarEmail::assignedUserName() const
{
    return d->mAssignedUserName;
}

void SugarEmail::setDateSent(const QString &value)
{
    d->mEmpty = false;
    d->mDateSent = value;
}

QString SugarEmail::dateSent() const
{
    return d->mDateSent;
}

void SugarEmail::setMessageId(const QString &value)
{
    d->mEmpty = false;
    d->mMessageId = value;
}

QString SugarEmail::messageId() const
{
    return d->mMessageId;
}

void SugarEmail::setParentType(const QString &value)
{
    d->mEmpty = false;
    d->mParentType = value;
}

QString SugarEmail::parentType() const
{
    return d->mParentType;
}

void SugarEmail::setParentId(const QString &value)
{
    d->mEmpty = false;
    d->mParentId = value;
}

QString SugarEmail::parentId() const
{
    return d->mParentId;
}

void SugarEmail::setFromAddrName(const QString &value)
{
    d->mEmpty = false;
    d->mFromAddrName = value;
}

QString SugarEmail::fromAddrName() const
{
    return d->mFromAddrName;
}

void SugarEmail::setToAddrNames(const QString &value)
{
    d->mEmpty = false;
    d->mToAddrNAmes = value;
}

QString SugarEmail::toAddrNames() const
{
    return d->mToAddrNAmes;
}

void SugarEmail::setCcAddrNames(const QString &value)
{
    d->mEmpty = false;
    d->mCcAddrNames = value;
}

QString SugarEmail::ccAddrNames() const
{
    return d->mCcAddrNames;
}

void SugarEmail::setData(const QMap<QString, QString>& data)
{
    d->mEmpty = false;

    const SugarEmail::AccessorHash accessors = SugarEmail::accessorHash();
    QMap<QString, QString>::const_iterator it = data.constBegin();
    for ( ; it != data.constEnd() ; ++it) {
        const SugarEmail::AccessorHash::const_iterator accessIt = accessors.constFind(it.key());
        if (accessIt != accessors.constEnd()) {
            (this->*(accessIt.value().setter))(it.value());
        }
    }

    // equivalent to this, but fully automated:
    //d->mId = data.value("id");
    //d->mName = data.value("name");
    // ...
}

QMap<QString, QString> SugarEmail::data() const
{
    QMap<QString, QString> data;

    const SugarEmail::AccessorHash accessors = SugarEmail::accessorHash();
    SugarEmail::AccessorHash::const_iterator it    = accessors.constBegin();
    SugarEmail::AccessorHash::const_iterator endIt = accessors.constEnd();
    for (; it != endIt; ++it) {
        const SugarEmail::valueGetter getter = (*it).getter;
        data.insert(it.key(), (this->*getter)());
    }

    // equivalent to this, but fully automated:
    //data.insert("id", d->mId);
    //data.insert("name", d->mName);
    // ...

    return data;
}

QString SugarEmail::mimeType()
{
    return QLatin1String("application/x-vnd.kdab.crm.email");
}

Q_GLOBAL_STATIC(SugarEmail::AccessorHash, s_accessors)

SugarEmail::AccessorHash SugarEmail::accessorHash()
{
    AccessorHash &accessors = *s_accessors();
    if (accessors.isEmpty()) {

        /*
id
name
date_entered
date_modified
modified_user_id
modified_by_name
created_by
created_by_name
deleted
assigned_user_id
assigned_user_name is missing !?!?

date_sent
message_id
parent_type
parent_id
from_addr_name
to_addrs_names
cc_addrs_names

Skipped fields:
bcc_addrs_names
reply_to_addr
type
status
flagged
reply_to_status
intent
mailbox_id

// The first example:

"modified_by_name" = "Valérie Blanc"
"created_by_name" = "Valérie Blanc"
"id" = "e37f08d6-fa9f-3b3f-73b4-551a5125fc22"
"date_entered" = "2015-03-31 07:50:49"
"date_modified" = "2015-03-31 12:58:09"
"assigned_user_id" = "e88a49f9-4ddd-2c3a-77ad-49dc7b5e72f9"
"modified_user_id" = "c34a548f-08cc-b8be-c43b-4f5f06f81621"
"created_by" = "c34a548f-08cc-b8be-c43b-4f5f06f81621"
"deleted" = "0"
"from_addr_name" = "mariececile.roue@orange.com"
"reply_to_addr" = "mariececile.roue@orange.com"
"to_addrs_names" = "David Faure <info-fr@kdab.com>"
"cc_addrs_names" = "GARDES Frederic IMT/OLPS <frederic.gardes@orange.com>, RAVANAT Nathalie IMT/DRH <nathalie.ravanat@orange.com>"
"date_sent" = "2015-03-31 07:43:00"
"message_id" = "2235ccac167495314bc9f50f32ba977e"
"name" = "RE: devis QML"
"type" = "inbound"
"status" = "read"
"flagged" = "0"
"reply_to_status" = "0"
"intent" = "pick"
"mailbox_id" = "418670f2-9466-ee20-75bd-52fdf8fc1e60"
"parent_type" = "Opportunities"
"parent_id" = "75443306-18e2-634a-ed06-54f5a41ccd00"
*/
        accessors.insert(QLatin1String("id"),
                         EmailAccessorPair(&SugarEmail::id, &SugarEmail::setId, QString()));
        accessors.insert(QLatin1String("name"),
                         EmailAccessorPair(&SugarEmail::name, &SugarEmail::setName,
                                          i18nc("@item:intable email name", "Name")));
        accessors.insert(QLatin1String("date_entered"),
                         EmailAccessorPair(&SugarEmail::dateEntered, &SugarEmail::setDateEntered, QString()));
        accessors.insert(QLatin1String("date_modified"),
                         EmailAccessorPair(&SugarEmail::dateModified, &SugarEmail::setDateModified, QString()));
        accessors.insert(QLatin1String("modified_user_id"),
                         EmailAccessorPair(&SugarEmail::modifiedUserId, &SugarEmail::setModifiedUserId, QString()));
        accessors.insert(QLatin1String("modified_by_name"),
                         EmailAccessorPair(&SugarEmail::modifiedByName, &SugarEmail::setModifiedByName, QString()));
        accessors.insert(QLatin1String("created_by"),
                         EmailAccessorPair(&SugarEmail::createdBy, &SugarEmail::setCreatedBy, QString()));
        accessors.insert(QLatin1String("created_by_name"),
                         EmailAccessorPair(&SugarEmail::createdByName, &SugarEmail::setCreatedByName, QString()));
        accessors.insert(QLatin1String("deleted"),
                         EmailAccessorPair(&SugarEmail::deleted, &SugarEmail::setDeleted, QString()));
        accessors.insert(QLatin1String("assigned_user_id"),
                         EmailAccessorPair(&SugarEmail::assignedUserId, &SugarEmail::setAssignedUserId, QString()));
        accessors.insert(QLatin1String("assigned_user_name"),
                         EmailAccessorPair(&SugarEmail::assignedUserName, &SugarEmail::setAssignedUserName,
                                          i18nc("@item:intable", "Assigned To")));

        accessors.insert(QLatin1String("date_sent"),
                         EmailAccessorPair(&SugarEmail::dateSent, &SugarEmail::setDateSent, QString()));
        accessors.insert(QLatin1String("message_id"),
                         EmailAccessorPair(&SugarEmail::messageId, &SugarEmail::setMessageId, QString()));
        accessors.insert(QLatin1String("parent_type"),
                         EmailAccessorPair(&SugarEmail::parentType, &SugarEmail::setParentType, QString()));
        accessors.insert(QLatin1String("parent_id"),
                         EmailAccessorPair(&SugarEmail::parentId, &SugarEmail::setParentId, QString()));
        accessors.insert(QLatin1String("from_addr_name"),
                         EmailAccessorPair(&SugarEmail::fromAddrName, &SugarEmail::setFromAddrName, QString()));
        accessors.insert(QLatin1String("to_addrs_names"),
                         EmailAccessorPair(&SugarEmail::toAddrNames, &SugarEmail::setToAddrNames, QString()));
        accessors.insert(QLatin1String("cc_addrs_names"),
                         EmailAccessorPair(&SugarEmail::ccAddrNames, &SugarEmail::setCcAddrNames, QString()));
    }
    return accessors;
}