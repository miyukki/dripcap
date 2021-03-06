#ifndef ITEM_HPP
#define ITEM_HPP

#include "item_value.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <v8.h>
#include <vector>

class Item {
public:
  Item();
  Item(const v8::FunctionCallbackInfo<v8::Value> &args);
  Item(v8::Local<v8::Value> value);
  Item(const Item &item);
  ~Item();

  std::string name() const;
  void setName(const std::string &name);
  std::string id() const;
  void setId(const std::string &id);
  std::string range() const;
  void setRange(const std::string &range);
  std::string summary() const;
  void setSummary(const std::string &summary);
  v8::Local<v8::Object> valueObject() const;
  ItemValue value() const;
  void setValue(v8::Local<v8::Object> value);

  std::vector<std::shared_ptr<Item>> items() const;
  void addItem(v8::Local<v8::Object> obj);
  std::shared_ptr<Item> item(const std::string &id) const;
  v8::Local<v8::Object> itemObject(const std::string &id) const;

private:
  class Private;
  std::unique_ptr<Private> d;
};

#endif
