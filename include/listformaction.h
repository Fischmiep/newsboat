#ifndef NEWSBOAT_LISTFORMACTION_H_
#define NEWSBOAT_LISTFORMACTION_H_

#include <cstdint>

#include "3rd-party/optional.hpp"

#include "formaction.h"
#include "listwidget.h"
#include "regexmanager.h"

namespace newsboat {

class ListFormAction : public FormAction {
public:
	ListFormAction(View* v, const std::string& context, std::string formstr,
		std::string list_name,
		ConfigContainer* cfg, RegexManager& r);

protected:
	bool process_operation(Operation op,
		bool automatic = false,
		std::vector<std::string>* args = nullptr) override;
	nonstd::optional<std::uint8_t> open_unread_items_in_browser(
		std::shared_ptr<RssFeed> feed,
		bool markread);

	ListWidget list;
};

} // namespace newsboat

#endif /* NEWSBOAT_LISTFORMACTION_H_ */
